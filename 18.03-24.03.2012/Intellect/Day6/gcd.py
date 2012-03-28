from fractions import gcd

fi = open("gcd.in")
n = int(fi.readline())
A = map(int, fi.readline().split(" "))
c = A[0]
for x in xrange(1, n):
    c = gcd(c, A[x])
open("gcd.out", "w").write("%d\n" % c)
