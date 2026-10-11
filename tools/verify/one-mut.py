# usage: one-mut.py MUTANTS.py NAME FILE — apply the one mutant whose name starts with NAME to FILE
import runpy, sys
muts = runpy.run_path(sys.argv[1])["MUTANTS"]
name, path = sys.argv[2], sys.argv[3]
m = [x for x in muts if x[0].startswith(name + " ")][0]
s = open(path, encoding="utf-8").read()
assert s.count(m[2]) == 1
open(path, "w", encoding="utf-8").write(s.replace(m[2], m[3]))
print("applied", m[0])
