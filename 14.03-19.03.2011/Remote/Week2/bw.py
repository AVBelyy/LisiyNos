#!/usr/bin/env python

first, second = [], []

fi, fo = open("bw.in"), open("bw.out", "w")
w, h = (int(x) for x in fi.readline().split())
first, second = [[]]*h, [[]]*h
for x in xrange(h): first[x] = [int(a) for a in fi.readline() if a != '\n']
for x in xrange(h): second[x] = [int(a) for a in fi.readline() if a != '\n']
table = [x for x in fi.readline() if x != '\n']

for y in xrange(h):
	for x in xrange(w):
		if   (first[y][x] == 0) and (second[y][x] == 0): fo.write(table[0])
		elif (first[y][x] == 0) and (second[y][x] == 1): fo.write(table[1])
		elif (first[y][x] == 1) and (second[y][x] == 0): fo.write(table[2])
		elif (first[y][x] == 1) and (second[y][x] == 1): fo.write(table[3])
	fo.write("\n")
