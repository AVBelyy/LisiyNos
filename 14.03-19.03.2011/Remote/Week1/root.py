#!/usr/bin/env python

A, n = open("root.in").readline().split()
A, n = int(A), float(n)

open("root.out", "w").write(str(int(round(pow(A, 1/n)))) + "\n")
