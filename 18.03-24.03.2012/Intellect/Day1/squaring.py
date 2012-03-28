from math import pi, sqrt

x, y, r = map(float, open("squaring.in").read().split(" "))
a = sqrt(pi)*r/2

x2, y2 = x-a, y+a
x3, y3 = x+a, y+a
x4, y4 = x+a, y-a
x1, y1 = x-a, y-a

open("squaring.out", "w").write("%.16f %.16f\n%.16f %.16f\n%.16f %.16f\n%.16f %.16f\n" % (x1, y1, x2, y2, x3, y3, x4, y4))
