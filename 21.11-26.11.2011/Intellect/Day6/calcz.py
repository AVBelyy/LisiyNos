a, b = open("calcz.in").read().split()
l = max(len(a), len(b))+1
a, b = "0"*(l-len(a))+a, "0"*(l-len(b))+b
r = [0]*l

for x in xrange(l-1, -1, -1):
    r[x] += int(a[x])+int(b[x])
    if r[x] > 9:
        r[x-1] += 1
        r[x] -= 10

open("calcz.out", "w").write("0" if r == [0, 0] else "".join(map(str, r)).lstrip("0"))
