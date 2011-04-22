#!/usr/bin/env python

with open('excess.in') as fi:
    n = int(fi.readline())
    a = [int(i) for i in fi.readline().split()]

a.sort()
a.append(-1)
prev = -1
count = 4
res = 0

for x in a:
	if x != prev:
		if count != 4:
			res = prev
			break
		prev = x
		count = 1
	else: count += 1

with open('excess.out', 'w') as fo:
    fo.write(str(res) + "\n")
