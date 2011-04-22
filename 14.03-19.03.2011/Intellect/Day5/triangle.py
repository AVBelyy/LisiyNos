#!/usr/bin/env python

from math import fabs

def Geron(ax, ay, bx, by, cx, cy):
	return fabs((bx-ax)*(cy-ay)-(cx-ax)*(by-ay))/2.0

def Inside(ax, ay, bx, by, cx, cy, px, py):
	s=Geron(ax, ay, bx, by, cx, cy)
	s1=Geron(ax, ay, bx, by, px, py)
	s2=Geron(bx, by, cx, cy, px, py)
	s3=Geron(cx, cy, ax, ay, px, py)
	if fabs(s-(s1+s2+s3)) < 0.001:
		return True
	else:
		return False

fi = open("triangle.in", "r")
fo = open("triangle.out", "w")
T = int(fi.readline())
for PeremennayaShetchik in xrange(T):
	x1, y1, x2, y2, x3, y3 = (float(a) for a in fi.readline().split())
	x, y = (float(a) for a in fi.readline().split())
	fo.write("YES\n" if Inside(x1, y1, x2, y2, x3, y3, x, y) else "NO\n")
fi.close()
fo.close()
