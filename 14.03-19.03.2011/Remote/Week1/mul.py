#!/usr/bin/env python

fi = open("mul.in", "r")
fo = open("mul.out", "w")
fo.write(str(long(fi.readline()) * long(fi.readline())) + "\n")
fi.close()
fo.close()

