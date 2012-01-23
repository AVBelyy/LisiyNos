#!/usr/bin/env python

from fractions import gcd
from functools import reduce

with open("dinner.in") as fi:
    k, m = map(int, fi.readline().split())
    n = list(map(int, fi.readline().split()))

s = []
for x in range(m):
    s.append([0]*k)    

def find(x, t):
    for i in range(k):
        if s[x][i] == t:
            return i
    return -1

def fill_with(i, j):
    v = s[i][j]
    # go up
    for x in range(i-1, -1, -1):
        if s[x][j]: break
        else: s[x][j] = v
    # go down
    for x in range(i+1, m):
        if s[x][j]: break
        else: s[x][j] = v

for i in range(m):
    if i != m-1:
        a = int(n[i]/(n[i]-n[i+1]))
        pos = find(i, a)
        if pos == -1: pos = find(i, 0)
        s[i][pos] = a
        s[i+1][pos] = a-1
        if a == 2:
            for x in range(i+2,m):
                s[x][pos] = 1

# try to fill in empty cells
for i in range(m):
    for j in range(k):
        fill_with(i, j)

# find completely empty columns
flag = False
for j in range(k):
    S = 0
    for i in range(m):
        S += s[i][j]
    if S == 0:
        g = [int(n[x]/reduce(lambda x, y: x*y, list(filter(None, s[x][:k])))) for x in range(m)]
        cell = reduce(lambda x, y: gcd(x,y), g)
        for i in range(m):
            s[i][j] = cell        

open("dinner.out", "w").write(" ".join(map(str, s[0]))+"\n" if (reduce(lambda x, y: x*y, s[0]) == n[0]) else "I AM SO SORRY :-(")