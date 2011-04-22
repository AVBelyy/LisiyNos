#!/usr/bin/env python

with open('valdiff.in') as fi:
    a, b, x1, x2 = (int(i) for i in fi.read().split())

f1 = a*x1 + float(x1)/b
f2 = a*x2 + float(x2)/b

f = a*(x1-x2) + (x1-x2)/float(b)

with open('valdiff.out', 'w') as fo:
    fo.write(('{:.5f}'.format(f)))
