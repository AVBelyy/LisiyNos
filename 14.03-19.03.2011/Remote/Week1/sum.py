#!/usr/bin/env python

fi = open("sum.in", "r")
fo = open("sum.out", "w")
fo.write(str(long(fi.readline()) + long(fi.readline())) + "\n")
fi.close()
fo.close()

