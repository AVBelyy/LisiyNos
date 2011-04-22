#!/usr/bin/env python

with open('line.in') as fi:
	x1, y1, x2, y2 = (float(i) for i in fi.readline().split())


with open('line.out', 'w') as fo:
	fo.write('{0:.3f} {1:.3f} {2:.3f}\n'.format(y1-y2, x2-x1, x1*y2-x2*y1))
