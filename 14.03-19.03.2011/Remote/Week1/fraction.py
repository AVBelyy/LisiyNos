#!/usr/bin/env python

from fractions import gcd

def process_fraction(f):
    if f[0] > f[1]:
        integer = f[0] // f[1]
        f[0] %= f[1]
    else:
        integer = 0
    common = gcd(*f)
    f[0] //= common
    f[1] //= common
    res = ''
    if integer:
        res += str(integer)+' '
    if f[0]:
        res += '{0}/{1}'.format(*f)
    return res

with open('fraction.in', 'r') as fi:
    fi.readline()
    tests = map(lambda x: [int(i) for i in x.split('/')], fi.readlines())
    results = map(process_fraction, tests)

with open('fraction.out', 'w') as fo:
    fo.write('\n'.join(results))
    fo.write('\n')
