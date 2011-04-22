#!/usr/bin/env python

from math import pi

with open("radius.in") as fi:
	R = float(fi.readline())

with open("radius.out", "w") as fo:
	fo.write("%.3f %.3f %.3f\n" % (2 * R, 2 * pi * R, pi * R * R))
