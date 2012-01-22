#/usr/bin/env python

import xml, xml.dom.minidom as md

replace = tuple(map(chr, tuple(range(ord('a'), ord('z')+1))+(ord('/'), ord('<'), ord('>'))))

fo = open("xml.out", "w")

def tryer(s, recur=False):
	try:
		md.parseString(s)
		# ALL RIGHT!
		fo.write(s[3:-4] + "\n")
		fo.close()
		exit(0)
	except xml.parsers.expat.ExpatError as E:
		S = E.args[0]
		if recur: return
		if S.startswith("no el"):
			st, end = s.rfind("<", 0, E.offset)+1, s.rfind(">", 0, E.offset)
			pos_r = range(st, end)
		if S.startswith("misma"):
			st, end = s.rfind("<", 0, E.offset-2)+1, s.rfind(">", 0, E.offset-2)
			pos_r = range(st, end)
		else:
			pos_r = (E.offset-1, E.offset, E.offset+1)
		for pos in pos_r:
			for ch in replace:
				tryer(s[:pos]+ch+s[pos+1:], True)

tryer("<a>"+open("xml.in").readline().strip()+"</a>")
fo.close()