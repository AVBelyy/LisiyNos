#!/usr/bin/env python

h, l = (int(x) for x in open("bandit.in").readline().split())

s = h + l - 1
open("bandit.out", "w").write("%d %d\n" % (s - h, s - l))
