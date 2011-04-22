#!/usr/bin/env python

from math import sqrt

with open('triangles.in') as fi:
	n = int(fi.readline())
	points = [[float(j) for j in i.split()] for i in fi.readlines()]

triangle = []
res = [[], 10**8]

def perimeter(x, y, z):
	a = sqrt((points[y][0]-points[x][0])**2 + (points[y][1]-points[x][1])**2)
	b = sqrt((points[z][0]-points[y][0])**2 + (points[z][1]-points[y][1])**2)
	c = sqrt((points[z][0]-points[x][0])**2 + (points[z][1]-points[x][1])**2)

	return a+b+c

for i in xrange(n):
	for j in xrange(i+1, n):
		for k in xrange(j+1, n):
			p = perimeter(i, j, k)
			if p < res[1]:
				res[0] = [str(i+1), str(j+1), str(k+1)]
				res[1] = p

with open('triangles.out', 'w') as fo:
	fo.write(' '.join(res[0]))
	fo.write('\n')
