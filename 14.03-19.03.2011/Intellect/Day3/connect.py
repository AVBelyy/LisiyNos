#!/usr/bin/env python

with open('connect.in') as fi:
    n, m = (int(i) for i in fi.readline().split())
    A = [([0]*n)[:] for i in xrange(n)]
    for i in xrange(m):
        u, v = (int(j)-1 for j in fi.readline().split())
        A[u][v] = 1
        A[v][u] = 1

visited = {}

def DFS(v):
    global visited, n
    for i in xrange(n):
        if A[v][i] and not i in visited:
            visited[i] = True
            DFS(i)

DFS(0)

with open('connect.out', 'w') as fo:
    fo.write('YES\n' if len(visited) == n else 'NO\n')
