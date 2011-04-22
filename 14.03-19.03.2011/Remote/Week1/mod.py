#!/usr/bin/env python

fi = open("mod.in", "r")
fo = open("mod.out", "w")
fo.write(str(long(fi.readline()) % long(fi.readline())) + "\n")
fi.close()
fo.close()

