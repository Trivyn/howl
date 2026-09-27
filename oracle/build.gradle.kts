// THE ORACLE PINS (Constraint b293cf6e: "pin exact ELK and HermiT versions in
// the repo"). Each version lives here once; `versions.properties` is generated
// from these same values, and the program refuses to run if the reasoner or
// OWL API it actually loaded reports anything else — dependency resolution
// substituting a version must fail, not silently change the oracle.
val elkVersion = "0.6.0"
val hermitVersion = "1.4.5.519"
val owlapiVersion = "5.1.20"
val slf4jVersion = "2.0.13"     // ELK 0.6.0's own
val logbackVersion = "1.3.14"   // ELK 0.6.0's own
val jdkVersion = 21

plugins {
    application
}

repositories {
    mavenCentral()
}

// JDK 21, not the host's newest: OWL API 5.1's Guava and Caffeine call
// sun.misc.Unsafe, which newer JDKs warn about on stderr — and the harness
// fails on any warning. The JVM is part of the oracle, so it is pinned too.
java {
    toolchain {
        languageVersion = JavaLanguageVersion.of(jdkVersion)
    }
}

dependencies {
    implementation("io.github.liveontologies:elk-owlapi:$elkVersion")
    implementation("net.sourceforge.owlapi:org.semanticweb.hermit:$hermitVersion") {
        // HermiT logs through commons-logging; jcl-over-slf4j routes it into
        // the same appender that fails the run on a warning.
        exclude(group = "commons-logging", module = "commons-logging")
    }
    // HermiT 1.4.5.519 was built against OWL API 5.1.9 and ELK 0.6.0 against
    // 5.1.20. Both run on ONE OWL API here; the capability probes are the
    // compatibility check.
    implementation("net.sourceforge.owlapi:owlapi-distribution") {
        version { strictly(owlapiVersion) }
    }
    implementation("org.slf4j:slf4j-api:$slf4jVersion")
    implementation("org.slf4j:jcl-over-slf4j:$slf4jVersion")
    implementation("ch.qos.logback:logback-classic:$logbackVersion")
}

dependencyLocking {
    lockAllConfigurations()
}

application {
    mainClass = "howl.oracle.Main"
}

tasks.processResources {
    val pins = mapOf("elk" to elkVersion, "hermit" to hermitVersion, "owlapi" to owlapiVersion,
                     "jdk" to jdkVersion.toString())
    inputs.properties(pins)
    filesMatching("versions.properties") { expand(pins) }
}

// THE LAUNCHER. `installDist`'s start script runs whatever `java` the host has
// on PATH, which is not the pinned JDK — the toolchain above governs only the
// compile. `build/oracle` runs the toolchain's own JVM, and Main refuses any
// other feature version, so the pin holds at run time too.
val launcher = javaToolchains.launcherFor { languageVersion = JavaLanguageVersion.of(jdkVersion) }
val writeLauncher by tasks.registering {
    dependsOn(tasks.installDist)
    val script = layout.buildDirectory.file("oracle")
    val java = launcher.map { it.executablePath.asFile.absolutePath }
    val lib = layout.buildDirectory.dir("install/oracle/lib").map { it.asFile.absolutePath }
    inputs.property("java", java)
    inputs.property("lib", lib)
    outputs.file(script)
    doLast {
        val f = script.get().asFile
        f.writeText("#!/bin/sh\nexec \"${java.get()}\" -cp \"${lib.get()}/*\" howl.oracle.Main \"\$@\"\n")
        f.setExecutable(true)
    }
}
tasks.assemble { dependsOn(writeLauncher) }
