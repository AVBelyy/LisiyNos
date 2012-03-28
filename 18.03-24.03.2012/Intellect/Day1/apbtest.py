c = int(open("apbtest.in").read())
a, b = (c/2, c-(c/2))
open("apbtest.out", "w").write("%d %d\n" % (a, b))
