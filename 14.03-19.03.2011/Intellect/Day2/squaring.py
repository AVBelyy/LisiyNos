#!/usr/bin/env python

from math import sqrt, pi

with open('squaring.in') as fi:
    x, y, r = (int(i) for i in fi.read().split())

a = sqrt(pi*(r**2))
y1 = y + a/2.0
y2 = y - a/2.0
x1 = x + a/2.0
x2 = x - a/2.0

with open('squaring.out', 'w') as fo:
    f_str = '%.12f %.12f\n'
    fo.write(f_str % (x2, y2))
    fo.write(f_str % (x2, y1))
    fo.write(f_str % (x1, y1))
    fo.write(f_str % (x1, y2))
