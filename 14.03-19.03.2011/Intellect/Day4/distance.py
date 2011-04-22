#!/usr/bin/env python

def Lev(s, t):
	m, n = len(s), len(t)
	d = [([0]*(n+1))[:] for i in xrange(m+1)]
	for i in xrange(m+1):
		d[i][0] = i
	for j in xrange(n+1):
		d[0][j] = j

	for j in xrange(1, n+1):
		for i in xrange(1, m+1):
			if s[i-1] == t[j-1]:
				d[i][j] = d[i-1][j-1]
			else:
				d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + 1)
	return str(d[m][n])

fi = open("distance.in", "r")
open("distance.out", "w").write(Lev(fi.readline(), fi.readline()) + "\n")
fi.close()
