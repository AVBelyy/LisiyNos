#!/usr/bin/env python

fi = open("sub.in", "r")
fo = open("sub.out", "w")
fo.write(str(long(fi.readline()) - long(fi.readline())) + "\n")
fi.close()
fo.close()

