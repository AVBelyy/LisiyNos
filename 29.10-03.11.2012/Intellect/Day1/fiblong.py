import math

sqrt5 = math.sqrt(5)

F1 = lambda n: int(round((((1+sqrt5)/2)**n-((1-sqrt5)/2)**n)/sqrt5))

def F2(n):
    F = [0]*(n+2)
    F[0] = 0
    F[1] = 1
    for x in xrange(2,n+1):
        F[x] = F[x-1]+F[x-2]
    return F[n]

n = int(open("fiblong.in").readline())
open("fiblong.out", "w").write(str(F2(n)))
