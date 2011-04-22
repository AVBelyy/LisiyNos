#!/usr/bin/env python

from math import sqrt, fabs

with open('twoc.in') as fi:
	x1, y1, x2, y2, r1, r2 = (int(i) for i in fi.readline().split())

fo = open('twoc.out', 'w')

d = sqrt((x2-x1)**2 + (y2-y1)**2)
if r1+r2 == d:
	print >> fo, 'Tangent: outside'
elif r1-r2 == d:
	print >> fo, 'Tangent: 1 in 2'
elif r2-r1 == d:
	print >> fo, 'Tangent: 2 in 1'
elif r1+r2 < d:
	print >> fo, 'Too far'
elif r1-r2 > d:
	print >> fo, '1 inside 2'
elif r2-r1 > d:
	print >> fo, '2 inside 1'
elif r1+r2 > d and fabs(r1-r2)<d:
	print >> fo, 'Intersect'
