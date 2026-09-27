package howl.oracle;

import org.semanticweb.HermiT.Configuration;
import org.semanticweb.elk.owlapi.ElkReasonerFactory;
import org.semanticweb.owlapi.apibinding.OWLManager;
import org.semanticweb.owlapi.formats.TurtleDocumentFormat;
import org.semanticweb.owlapi.io.FileDocumentSource;
import org.semanticweb.owlapi.io.OWLOntologyLoaderMetaData;
import org.semanticweb.owlapi.model.IRI;
import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLDataFactory;
import org.semanticweb.owlapi.model.OWLDocumentFormat;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.model.OWLOntologyManager;
import org.semanticweb.owlapi.reasoner.InferenceType;
import org.semanticweb.owlapi.reasoner.OWLReasoner;
import org.semanticweb.owlapi.util.VersionInfo;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.Properties;
import java.util.Set;
import java.util.TreeSet;

/**
 * The differential oracle: reasons over each file with ELK or HermiT and writes
 * what it entails in HOWL's own report grammar (SPEC.md §10 item 1).
 *
 * <pre>
 * oracle report --reasoner elk    --tripwire FILE --out DIR FILE...
 * oracle report --reasoner hermit                 --out DIR FILE...
 * oracle convert                                  --out DIR FILE...
 * </pre>
 *
 * <p>{@code convert} re-serializes each file as Turtle through the same pinned
 * OWL API, for inputs HOWL cannot read directly (ELK's conformance tests are in
 * functional syntax). It fails a file on the same conditions as {@code report},
 * so a lossy conversion never reaches HOWL.
 *
 * <p>THE OUTPUT IS BOTTOM-COMPRESSED, EXACTLY AS HOWL'S IS. For every named
 * class A of the signature, plus owl:Thing and minus owl:Nothing: an
 * unsatisfiable A is {@code unsat A} with the single line {@code sub A
 * owl:Nothing}; a satisfiable A is {@code sub A B} for every named B it is
 * subsumed by, A itself and owl:Thing included. An inconsistent ontology is
 * {@code inconsistent true} and nothing else, since every pair is entailed
 * there and a hierarchy carries no information. That is §10's "canonicalize
 * both sides to the same bottom-collapsed form", and it is what lets
 * corpus/entdiff.py compare the two as sets.
 *
 * <p>A FILE FAILS, and gets no report, when the OWL API left a triple unparsed
 * or guessed a declaration, or when anything logged a warning while it was
 * loaded or reasoned over. Either means the oracle may have processed a
 * different theory from the one HOWL did. Exit 0 when every file produced a
 * report, 1 when any failed, 3 on a usage error, a version mismatch or a dead
 * tripwire.
 */
public final class Main {
    private static final String THING = "http://www.w3.org/2002/07/owl#Thing";
    private static final String NOTHING = "http://www.w3.org/2002/07/owl#Nothing";

    /** Report lines compare by code point, the order HOWL's sorts use. */
    private static final Comparator<String> CODE_POINT_ORDER = (a, b) -> {
        int i = 0, j = 0;
        while (i < a.length() && j < b.length()) {
            int ca = a.codePointAt(i), cb = b.codePointAt(j);
            if (ca != cb) return Integer.compare(ca, cb);
            i += Character.charCount(ca);
            j += Character.charCount(cb);
        }
        return Integer.compare(a.length() - i, b.length() - j);
    };

    private static final class Usage extends Exception {
        Usage(String message) { super(message); }
    }

    /** A condition that makes the whole run meaningless, not just one file. */
    private static final class Abort extends Exception {
        Abort(String message) { super(message); }
    }

    public static void main(String[] args) {
        try {
            System.exit(run(args));
        } catch (Usage u) {
            System.out.println("usage error: " + u.getMessage());
            System.out.println("usage: oracle report --reasoner elk|hermit [--tripwire FILE] --out DIR FILE...");
            System.out.println("       oracle convert --out DIR FILE...");
            System.exit(3);
        } catch (Abort a) {
            System.out.println("ABORT " + a.getMessage());
            System.exit(3);
        }
    }

    private static int run(String[] args) throws Usage, Abort {
        if (args.length == 0 || !(args[0].equals("report") || args[0].equals("convert"))) {
            throw new Usage("the commands are `report` and `convert`");
        }
        boolean convert = args[0].equals("convert");
        String reasoner = null;
        Path out = null;
        File tripwire = null;
        List<File> files = new ArrayList<>();
        for (int i = 1; i < args.length; i++) {
            switch (args[i]) {
                case "--reasoner" -> reasoner = value(args, ++i, "--reasoner");
                case "--out" -> out = Path.of(value(args, ++i, "--out"));
                case "--tripwire" -> tripwire = new File(value(args, ++i, "--tripwire"));
                default -> {
                    if (args[i].startsWith("--")) throw new Usage("unknown flag " + args[i]);
                    files.add(new File(args[i]));
                }
            }
        }
        if (out == null || files.isEmpty()) throw new Usage("--out and at least one FILE are required");
        if (convert && (reasoner != null || tripwire != null)) throw new Usage("convert takes no --reasoner or --tripwire");
        if (!convert && reasoner == null) throw new Usage("report requires --reasoner");
        if (!convert && !reasoner.equals("elk") && !reasoner.equals("hermit")) throw new Usage("--reasoner is elk or hermit");
        // The tripwire is ELK's: it proves the warning capture is live by
        // feeding ELK a construct it is known to reject with a warning. HermiT
        // is complete for OWL 2 DL and rejects nothing in the fixtures by
        // warning, so it has no such input — and a tripwire that cannot fire
        // must not be accepted as if it had been checked.
        if ("elk".equals(reasoner) && tripwire == null) throw new Usage("--reasoner elk requires --tripwire FILE");
        if ("hermit".equals(reasoner) && tripwire != null) throw new Usage("--tripwire applies to elk only");

        Properties pins = pins();
        // Checked against the MANIFEST of the jar each class was loaded from,
        // which reads "<release>.<build timestamp>". Not getReasonerVersion():
        // HermiT 1.4.5.519 reports 1.4.1.513 there, a string its release never
        // updated — the manifest is what identifies the artifact on the path.
        String owlapi = checkRelease("OWL API", VersionInfo.getVersionInfo().getVersion(), pins.getProperty("owlapi"));
        checkRelease("elk", ElkReasonerFactory.class.getPackage().getImplementationVersion(), pins.getProperty("elk"));
        checkRelease("hermit", org.semanticweb.HermiT.Reasoner.class.getPackage().getImplementationVersion(),
                pins.getProperty("hermit"));
        int jdk = Runtime.version().feature();
        if (jdk != Integer.parseInt(pins.getProperty("jdk"))) {
            throw new Abort("running on JDK " + jdk + ", pinned " + pins.getProperty("jdk")
                    + " (run build/oracle, not the installDist script)");
        }
        try {
            Files.createDirectories(out);
        } catch (IOException e) {
            throw new Usage("cannot create " + out + ": " + e.getMessage());
        }
        WarningRecorder.drain();
        if (convert) return convertAll(files, out);
        String header = "reasoner " + reasoner + " " + pins.getProperty(reasoner)
                + " owlapi " + owlapi + " jvm " + System.getProperty("java.vm.version");

        // Checked BEFORE the first file and AFTER the last. ELK may log a given
        // unsupported feature once and then stay quiet; the second firing
        // shows it did not go quiet partway through this run.
        if (tripwire != null) fireTripwire(reasoner, tripwire, "before");
        int failed = 0;
        for (File f : files) {
            try {
                List<String> lines = reason(reasoner, f);
                List<String> warnings = WarningRecorder.drain();
                if (!warnings.isEmpty()) {
                    failed++;
                    System.out.println("FAIL " + f + ": " + warnings.size() + " warning(s)");
                    for (String w : warnings) System.out.println("  " + w);
                    continue;
                }
                List<String> text = new ArrayList<>();
                text.add("oracle-report 1");
                text.add(header);
                text.addAll(lines);
                Files.write(out.resolve(reportName(f)), text, StandardCharsets.UTF_8);
                System.out.println("ok   " + f);
            } catch (Abort a) {
                throw a;
            } catch (Exception e) {
                failed++;
                WarningRecorder.drain();
                System.out.println("FAIL " + f + ": " + e.getClass().getSimpleName() + ": " + e.getMessage());
            }
        }
        if (tripwire != null) fireTripwire(reasoner, tripwire, "after");
        return failed == 0 ? 0 : 1;
    }

    /** Each FILE to {@code DIR/<name>.ttl}; the format is detected by the OWL API. */
    private static int convertAll(List<File> files, Path out) {
        int failed = 0;
        for (File f : files) {
            try {
                OWLOntologyManager manager = OWLManager.createOWLOntologyManager();
                OWLOntology ont = manager.loadOntologyFromOntologyDocument(f);
                // RDF syntaxes report dropped triples in the loader metadata;
                // the functional-syntax parser has none and throws instead.
                if (ont.getFormat() != null && ont.getFormat().getOntologyLoaderMetaData().isPresent()) {
                    refuseLossyParse(ont);
                }
                Path target = out.resolve(f.getName().replaceFirst("\\.[^.]*$", "") + ".ttl");
                manager.saveOntology(ont, new TurtleDocumentFormat(), IRI.create(target.toFile()));
                List<String> warnings = WarningRecorder.drain();
                if (!warnings.isEmpty()) {
                    failed++;
                    Files.deleteIfExists(target);
                    System.out.println("FAIL " + f + ": " + warnings.size() + " warning(s)");
                    for (String w : warnings) System.out.println("  " + w);
                    continue;
                }
                System.out.println("ok   " + f);
            } catch (Exception e) {
                failed++;
                WarningRecorder.drain();
                System.out.println("FAIL " + f + ": " + e.getClass().getSimpleName() + ": " + e.getMessage());
            }
        }
        return failed == 0 ? 0 : 1;
    }

    private static String value(String[] args, int i, String flag) throws Usage {
        if (i >= args.length) throw new Usage(flag + " needs a value");
        return args[i];
    }

    /** The report name mirrors the golden naming: {@code <dir>-<name>.report}. */
    private static String reportName(File f) {
        String name = f.getName().replaceFirst("\\.ttl$", "");
        File parent = f.getAbsoluteFile().getParentFile();
        return (parent == null ? "" : parent.getName() + "-") + name + ".report";
    }

    private static Properties pins() throws Abort {
        Properties p = new Properties();
        try (InputStream in = Main.class.getResourceAsStream("/versions.properties")) {
            if (in == null) throw new Abort("versions.properties is missing from the build");
            p.load(in);
        } catch (IOException e) {
            throw new Abort("cannot read versions.properties: " + e.getMessage());
        }
        return p;
    }

    private static void fireTripwire(String reasoner, File tripwire, String when) throws Abort {
        try {
            reason(reasoner, tripwire);
        } catch (Abort a) {
            throw a;
        } catch (Exception e) {
            // A refusal by exception is not the capture this checks.
            WarningRecorder.drain();
            throw new Abort("tripwire " + tripwire + " (" + when + ") threw instead of warning: " + e);
        }
        if (WarningRecorder.drain().isEmpty()) {
            throw new Abort("tripwire " + tripwire + " (" + when + ") produced no warning: the warning capture is dead, "
                    + "so a warning on any other file would have gone unseen");
        }
    }

    private static List<String> reason(String reasoner, File f) throws Exception {
        OWLOntologyManager manager = OWLManager.createOWLOntologyManager();
        OWLOntology ont = manager.loadOntologyFromOntologyDocument(
                new FileDocumentSource(f, new TurtleDocumentFormat()));
        refuseLossyParse(ont);

        OWLReasoner r;
        if (reasoner.equals("hermit")) {
            Configuration c = new Configuration();
            c.warningMonitor = w -> WarningRecorder.record("WARN hermit: " + w);
            r = new org.semanticweb.HermiT.ReasonerFactory().createReasoner(ont, c);
        } else {
            r = new ElkReasonerFactory().createReasoner(ont);
        }
        try {
            List<String> lines = new ArrayList<>();
            if (!r.isConsistent()) {
                lines.add("inconsistent true");
                return lines;
            }
            lines.add("inconsistent false");
            r.precomputeInferences(InferenceType.CLASS_HIERARCHY);
            OWLDataFactory df = manager.getOWLDataFactory();
            Set<OWLClass> classes = new TreeSet<>();
            ont.classesInSignature().forEach(classes::add);
            classes.add(df.getOWLThing());
            classes.remove(df.getOWLNothing());
            Set<OWLClass> unsat = r.getUnsatisfiableClasses().getEntitiesMinusBottom();
            List<String> body = new ArrayList<>();
            for (OWLClass a : classes) {
                String ai = a.getIRI().toString();
                if (unsat.contains(a)) {
                    body.add("unsat " + ai);
                    body.add("sub " + ai + " " + NOTHING);
                    continue;
                }
                Set<String> supers = new TreeSet<>(CODE_POINT_ORDER);
                r.getSuperClasses(a, false).entities().forEach(b -> supers.add(b.getIRI().toString()));
                r.getEquivalentClasses(a).entities().forEach(b -> supers.add(b.getIRI().toString()));
                supers.add(ai);
                supers.add(THING);
                supers.remove(NOTHING);
                for (String b : supers) body.add("sub " + ai + " " + b);
            }
            body.sort(CODE_POINT_ORDER);
            lines.addAll(body);
            return lines;
        } finally {
            r.dispose();
        }
    }

    /**
     * The OWL API's RDF parsers drop what they cannot map and report it only in
     * the loader metadata, so an unparsed triple is a silently smaller theory.
     */
    private static void refuseLossyParse(OWLOntology ont) throws Exception {
        OWLDocumentFormat format = ont.getFormat();
        if (format == null) throw new IllegalStateException("no document format recorded");
        Optional<OWLOntologyLoaderMetaData> meta = format.getOntologyLoaderMetaData();
        if (meta.isEmpty()) throw new IllegalStateException("no loader metadata: cannot confirm every triple was parsed");
        long unparsed = meta.get().getUnparsedTriples().count();
        if (unparsed > 0) {
            StringBuilder sb = new StringBuilder(unparsed + " unparsed triple(s):");
            meta.get().getUnparsedTriples().limit(10).forEach(t -> sb.append("\n    ").append(t));
            throw new IllegalStateException(sb.toString());
        }
        int guessed = meta.get().getGuessedDeclarations().size();
        if (guessed > 0) {
            throw new IllegalStateException(guessed + " guessed declaration(s): " + meta.get().getGuessedDeclarations());
        }
    }

    /** The pinned release, or abort: a substituted artifact is a different oracle. */
    private static String checkRelease(String what, String full, String pinned) throws Abort {
        if (full == null || !(full.equals(pinned) || full.startsWith(pinned + "."))) {
            throw new Abort(what + " on the class path is " + full + ", pinned " + pinned);
        }
        return pinned;
    }
}
