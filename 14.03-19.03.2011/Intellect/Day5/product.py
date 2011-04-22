#!/usr/bin/env python

vectors = []

with open('product.in') as fi:
	n = int(fi.readline())
	vectors = [[float(j) for j in fi.readline().split()] for i in xrange(2)]

with open('product.out', 'w') as fo:
	fo.write('{0:.3f}'.format(reduce(lambda x,y: x+y, [vectors[0][i] * vectors[1][i] for i in xrange(n)])))
	fo.write('\n')
