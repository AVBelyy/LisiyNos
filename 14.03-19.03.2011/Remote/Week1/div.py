#!/usr/bin/env python

fi = open("div.in", "r")
fo = open("div.out", "w")
fo.write(str(long(fi.readline()) / long(fi.readline())) + "\n")
fi.close()
fo.close()

