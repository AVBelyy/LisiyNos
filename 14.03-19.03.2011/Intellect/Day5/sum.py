#!/usr/bin/env python

vectors = []

with open('sum.in') as fi:
	n = int(fi.readline())
	vectors = [[float(j) for j in fi.readline().split()] for i in xrange(2)]

with open('sum.out', 'w') as fo:
	fo.write(' '.join(['{0:.3f}'.format(vectors[0][i] + vectors[1][i]) for i in xrange(n)]))
	fo.write('\n')
