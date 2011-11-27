f, w = [], []

def bylength(w1, w2):
    return len(w2) - len(w1)

def find(s, path):
    global f
    if not s:
        for x, y in path:
            f[y] = f[y][:x]+"#"+f[y][x+1:]
            print "SLAVA"
        return
    if path == ():
        for n in xrange(len(f)):
            i = f[n].find(s[0])
            if i > 0:
                find(s[1:], ((i, n),))
    else:
        x, y = path[-1]
        for i in xrange(-1, 2):
            for j in xrange(-1, 2):
                if i+j and f[i+y][j+x] == s[0]:
                    find(s[1:], path+((j+x, i+y),))

with open("puzzle.in") as fi:
    n, m = map(int, fi.readline().split())
    f.append("#"*(n+2))
    for x in xrange(n):
        f.append("#"+fi.readline().rstrip()+"#")
    f.append("#"*(n+2))
    for x in xrange(m):
        w.append(fi.readline().rstrip())
    w.sort(cmp=bylength)
    for x in w:
        find(x, ())

print "\n".join(f)
s = ""
for l in f:
    s += l.replace("#", "")
open("puzzle.out", "w").write(s+"\n")
