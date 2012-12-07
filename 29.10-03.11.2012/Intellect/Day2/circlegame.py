def mex(a):
    x = 0
    while True:
        if x not in a:
            return x
        x += 1

#map(int, open("circlegame.in"))[1:]:
f = [0]
for x in xrange(1,201):
    m = []
    for y in xrange((x-2)/2+1):
        m.append(f[y] ^ f[x-y-2])
    f.append(mex(m))

ans = []
for n in map(int, open("circlegame.in"))[1:]:
    if n < 68:
        c = f[n]
    else:
        c = f[n % 34 + 68]
    ans.append(53 if c else 34)

open("circlegame.out", "w").write("\n".join(map(str, ans)))
