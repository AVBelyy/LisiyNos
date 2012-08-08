#!/usr/bin/env python

INF = 10**8

with open('graph.in') as fi:
    n, m, s = (int(i) for i in fi.readline().split())
    A = [([INF]*n)[:] for i in xrange(n)]
    for i in xrange(m):
        u, v = (int(j)-1 for j in fi.readline().split())
        A[u][v] = 1
        A[v][u] = 1

def calc(x, y):
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
    return res

with open('graph.out', 'w') as fo:
    for y in xrange(n):
        if calc(s-1, y) != -1:
            fo.write("%d " % (y+1))
    fo.write("\n")
