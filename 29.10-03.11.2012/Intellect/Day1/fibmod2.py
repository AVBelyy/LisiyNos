import math

sqrt5 = math.sqrt(5)

def Fib(n):
    F = [0]*(n+2)
    F[0] = 0
    F[1] = 1
    for x in xrange(2,n+1):
        F[x] = F[x-1]+F[x-2]
    return F[n]

n, m = map(int, open("fibmod2.in").readline().split())
open("fibmod2.out", "w").write(str(Fib(n)%m))
