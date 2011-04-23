#!/usr/bin/env python

open("dwarf.out", "w").write(str(int(open("dwarf.in").readline()) % 7))
