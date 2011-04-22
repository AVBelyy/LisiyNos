#!/usr/bin/env python

INF = 0

with open("wave.in", "r") as fi:
    n, m, s = (int(a) for a in fi.readline().split())
    s -= 1
    A = [([INF]*n)[:] for i in xrange(n)]                                       
    for i in xrange(m):                                                         
        u, v = (int(j)-1 for j in fi.readline().split())                     
        A[u][v] = 1 
        A[v][u] = 1 

Q = []
visited = {s: True}
Q.append(s)
res = []
while Q:
    c = Q.pop(0)
    res.append(str(c+1))
    for i in xrange(n):
        if A[c][i] and i not in visited:
            visited[i] = True
            Q.append(i)

with open("wave.out", "w") as fo:
    fo.write('{0}\n{1}\n'.format(len(res), ' '.join(res)))
