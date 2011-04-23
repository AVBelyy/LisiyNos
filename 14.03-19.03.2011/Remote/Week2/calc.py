#!/usr/bin/env python

to_calc = open("calc.in").readline()
parsed = ""
for c in to_calc:
	if c in ("+", "-", "*", "/"):
		parsed += ".0"
	parsed += c
open("calc.out", "w").write(str(eval(parsed)))
