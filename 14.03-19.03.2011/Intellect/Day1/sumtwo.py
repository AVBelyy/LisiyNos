#!/usr/bin/env python

with open("sumtwo.in") as fi:
    n, x = (int(a) for a in fi.readline().split())
    a = [int(a) for a in fi.readline().split()]

i = 0
j = n-1

result = False

while i<=j:
    if a[i] + a[j] == x:
        result = True
        break
    if a[i] + a[j] < x:
        i += 1
    else:
        j -= 1

with open("sumtwo.out", "w") as fo:
    fo.write("YES\n" if result else "NO\n")
