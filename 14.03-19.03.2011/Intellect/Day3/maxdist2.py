#!/usr/bin/env python

INF = 10**8

def dest(x1, y1, x2, y2):
    return (float(x2-x1)**2 + float(y2-y1)**2)**0.5

with open('maxdist.in') as fi:
    n = int(fi.readline())
    A = [([INF]*n)[:] for i in xrange(n)]
    coords = []
    for i in xrange(n):
        x, y = (int(j) for j in fi.readline().split())
        coords.append((x, y))
    m = int(fi.readline())
    for i in xrange(m):
        u, v = (int(j)-1 for j in fi.readline().split())
        w = dest(*(coords[u] + coords[v]))
        A[u][v] = min(A[u][v], w)
        A[v][u] = min(A[v][u], w)

def dijkstra(v):
    w = [INF]*n
    b = [False]*n
    M = INF

    w[v] = 0
    l = v
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
    
    return max(w)

m = 0

for i in xrange(n):
    r = dijkstra(i)
    
    if r > m and r != INF:
        m = r

with open('maxdist.out', 'w') as fo:
    fo.write('-1\n' if m == 0 else '{0:.8f}\n'.format(m))
