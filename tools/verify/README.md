# Evidence harnesses

The scripts behind the tallies in SPEC §7 and in each PR body: depth, test mutants, contract
mutants and vacuity. Until slice 8 they lived in a session scratchpad, and a reboot lost them.

Each script edits files, so run it on a **scratch copy** of the tree, never the working tree.
The copy takes the working tree as it is, uncommitted changes included; `../slop-rdf` must sit
beside it, and `make golden` needs the corpus:

```sh
set -e
T=$(mktemp -d)/howl
mkdir -p "$T"
tar -c --exclude ./.git --exclude ./.moosedev --exclude ./build --exclude ./corpus/vendor --exclude ./oracle/build \
    --exclude ./rust/target . | tar -x -C "$T"
ln -sfn "$PWD/../slop-rdf" "$(dirname "$T")/slop-rdf"
ln -s "$PWD/corpus/vendor" "$T/corpus/vendor"
```

`mutate.py` first checks that the unmutated copy passes `make test` and `make golden`, and stops
if it does not. A verdict from a copy that was already red would mean nothing.

| Script | What it shows |
|---|---|
| `depth.py [--min N] FILE…` | The functions nested N or deeper (default 13). New code stays at 12 or less. |
| `mutate.py TREE MUTANTS.py LOG` | Each test mutant is red. It regenerates the C, then runs `make test` and `make golden`. `SLOP_HOME` must name the toolchain that generates the committed C. |
| `mutverify.py TREE MUTANTS.py LOG` | Each contract mutant is refuted, and by which contracts. |
| `casevac.py TREE LOG FILE…` | No guarded post is vacuous: each `(implies C P)`'s twin `(implies C (not P))` must fail. |
| `one-mut.py MUTANTS.py NAME FILE` | Applies one mutant, to look at it by hand. |

A mutants file defines `MUTANTS`, a list of `(name, file, old, new)`, where `old` occurs exactly
once in `file`. `mutverify.py` and `casevac.py` run `$SLOP verify`; `SLOP` defaults to `slop`.
