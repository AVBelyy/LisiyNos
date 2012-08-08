n, f = long(open("fib.in").read()), [1, 1]
for x in range(2, n): f += [f[x-2]+f[x-1]]
open("fib.out", "w").write("%d\n" % f[n-1])
