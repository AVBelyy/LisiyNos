def mm(a, b, m):
    return ((a%m)*(b%m))%m

def multiply(a, b, m):
    #return (((mm(a[0][0],b[0][0],m)+mm(a[0][1],b[1][0],m))%m, (mm(a[0][0],b[0][1],m)+mm(a[0][1],b[1][1],m))%m),
    #        ((mm(a[1][0],b[0][0],m)+mm(a[1][1],b[1][0],m))%m, (mm(a[1][0],b[0][1],m)+mm(a[1][1],b[1][1],m))%m))
    res = [[0,0],[0,0]]
    for i in xrange(2):
        for j in xrange(2):
            for k in xrange(2):
                res[i][j] = (res[i][j]+a[i][k]*b[k][j])%m
    return res

def Fib(n, m):
    if n < 2: return n%m
    A = ((1,1), (1,0))
    res = ((1,1), (1,0))
    while n > 0:
        if n % 2:
            res = multiply(res, A, m)
        A = multiply(A, A, m)
        n /= 2
    return res[0][0]

n, m = map(int, open("fibmod.in").readline().split())
open("fibmod.out", "w").write(str(Fib(n-2, m)))
