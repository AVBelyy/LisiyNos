#!/usr/bin/env python

from math import sqrt

with open('vector.in') as fi:
	x, y, z = (float(i) for i in fi.readline().split())

with open('vector.out', 'w') as fo:
	fo.write('{0:.2f}\n'.format(sqrt(x**2 + y**2 + z**2)))
