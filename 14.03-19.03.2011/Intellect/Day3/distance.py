#!/usr/bin/env python

INF = 10**8

with open('distance.in') as fi:
    n, m = (int(i) for i in fi.readline().split())
    A = [([INF]*n)[:] for i in xrange(3)]
    for i in xrange(m):
        u, v, w = (int(j)-1 for j in fi.readline().split())
        w += 1
        A[u][v] = min(A[u][v], w)
        A[v][u] = min(A[v][u], w)

    x, y = (int(i)-1 for i in fi.readline().split())

if x == y:
    res = 0
else:
    w = [INF]*n
    b = [False]*n
    M = INF

    w[x] = 0
    l = x

    N = 0

    while 1:
        b[l] = True
        M = INF
        for i in xrange(n):
            if not b[i]:
                w[i] = min(w[i], w[l] + A[l][i])
                if w[i] < M:
                    M = w[i]
                    N = i

        l = N

        if M == INF: break

    res = w[y] if w[y] != INF else -1

with open('distance.out', 'w') as fo:
    fo.write('{0}\n'.format(res))
