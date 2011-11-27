expr = open("table.in").readline().rstrip().lower()
fo = open("table.out", "w")
if "z" in expr:
    fo.write("X Y Z\n");
    for x in xrange(2):
        for y in xrange(2):
            for z in xrange(2):
                fo.write("%d %d %d " % (x, y, z))
                fo.write("%d\n" % eval(expr))
else:
    fo.write("X Y\n")
    for x in xrange(2):
        for y in xrange(2):
            fo.write("%d %d " % (x, y))
            fo.write("%d\n" % eval(expr))
