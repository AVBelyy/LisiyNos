#!/usr/bin/env python

INF = 10**10

def dest(x1, y1, x2, y2):
    return (float(x2-x1)**2 + float(y2-y1)**2)**0.5

with open('maxdist.in') as fi:
    n = int(fi.readline())
    A = [([INF]*n)[:] for i in xrange(n)]
    for i in xrange(n):
        A[i][i] = 0
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

w = [INF]*n
b = [False]*n

w[x] = 0
l = 1
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

print w

with open('maxdist.out', 'w') as fo:
    fo.write('-1\n' if INF in w else '{0:7f}\n'.format(max(w)))
