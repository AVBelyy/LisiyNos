#!/usr/bin/env python

import re

nonzero = "[1-9]"
e = "(E|e)"
sign = "(\+|\-)"
digit = "(0|%s)" % nonzero
anydigits = "(%s*)" % digit
exponent = "(|%s%s%s%s)" % (e, sign, nonzero, anydigits)
fraction = "(|\.%s%s)" % (anydigits, nonzero)
mantissa = "(%s%s)" % (nonzero, fraction)
real = re.compile("^(0|%s%s)$" % (mantissa, exponent))

parser = lambda s: "Yes" if real.match(s.rstrip()) else "No"
open("E.OUT", "w").write("\n".join(map(parser, open("E.IN"))[1:]))
