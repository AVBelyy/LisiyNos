#!/usr/bin/env python

from fractions import gcd

fi = open("simple2.in", "r")
fo = open("simple2.out", "w")
for x in xrange(int(fi.readline())):
	a, b = (int(i) for i in fi.readline().split())	
	fo.write("YES\n" if gcd(a, b) == 1 else "NO\n")
fi.close()
fo.close()
