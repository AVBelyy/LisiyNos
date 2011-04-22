#!/usr/bin/env python

with open('valsum.in') as fi:
    fi.readline()
    x = [int(i) for i in fi.readline().split()]

s_x = reduce(lambda x,y: x+y, x)
s_1x = reduce(lambda x,y: x+y, map(lambda x: 1.0/x, x))


with open('valsum.out', 'w') as fo:
    fo.write('{:.14f}'.format(s_x + s_1x))
