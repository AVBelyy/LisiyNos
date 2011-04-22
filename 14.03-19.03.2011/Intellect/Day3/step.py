#!/usr/bin/env python

with open('step.in') as fi:
    n, m, s = (int(i) for i in fi.readline().split())
    A = [([0]*n)[:] for i in xrange(n)]
    for i in xrange(m):
        u, v = (int(j)-1 for j in fi.readline().split())
        A[u][v] = 1
        A[v][u] = 1

visited = {}
res = []
def DFS(v):
    global visited, n, res
    #if not v in visited:
    res.append(str(v+1))
    for i in xrange(n):
        if A[v][i] and not i in visited:
            visited[i] = True
            DFS(i)

visited[s-1] = True
DFS(s-1)

res2 = res[:-1]
res2.reverse()
res += res2

with open('step.out', 'w') as fo:
    fo.write(str(len(res))+'\n')
    fo.write(' '.join(res))
    fo.write('\n')
    pass
