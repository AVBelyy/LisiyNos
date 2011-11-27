#!/usr/bin/env python
def proc(m, l):
    global fo, vec, n, k
    if m == n:
        if not l:
            for i in xrange(k):
                for j in xrange(n):
                    if vec[j] == i:
                        fo.write("%d " % (j+1))
                fo.write("\n")
        return
    for i in xrange(k-l):
        vec[m] = i
        proc(m + 1, l)
    vec[m] = k - l
    proc(m + 1, l - 1)

fo = open("part2sets.out", "w")
n, k = map(int, open("part2sets.in").readline().split())
vec = [0]*n
proc(0, k)
