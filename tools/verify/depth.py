# usage: depth.py [--min N] FILE... — functions whose paren depth (strings, comments skipped) is >= N (default 13)
import sys,re
args=sys.argv[1:]; mn=13
if args and args[0]=="--min": mn=int(args[1]); args=args[2:]
for p in args:
    s=open(p,encoding='utf-8').read();i=0;d=0;ln=1;cur=None;res=[]
    while i<len(s):
        c=s[i]
        if c=="\n": ln+=1
        elif c==";":
            while i<len(s) and s[i]!="\n": i+=1
            continue
        elif c=='"':
            i+=1
            while s[i]!='"':
                if s[i]=="\\": i+=1
                elif s[i]=="\n": ln+=1
                i+=1
        elif c=="(":
            d+=1
            if d==2 and s.startswith("(fn ",i): cur=[re.match(r"\(fn\s+(\S+)",s[i:]).group(1),ln,0]
            if cur: cur[2]=max(cur[2],d-1)
        elif c==")":
            if cur and d==2: res.append(cur); cur=None
            d-=1
        i+=1
    print(p, "max", max([r[2] for r in res] or [0]), [tuple(r) for r in res if r[2]>=mn], "balance", d)
