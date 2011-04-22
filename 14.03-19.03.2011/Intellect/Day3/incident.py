#!/usr/bin/env python

with open('incident.in') as fi:
    n, m = (int(i) for i in fi.readline().split())
    edges = [map(int, i.split()) for i in fi.readlines()] 

with open('incident.out', 'w') as fo:
    for i in xrange(1, n+1):
        temp = []
        for e in edges:
            temp.append(str(int(i in e)))
        fo.write(' '.join(temp))
        fo.write('\n')
