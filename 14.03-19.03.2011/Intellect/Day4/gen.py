
l=[range(1,32)]
l += [ ([1]+[0]*30)[:] for i in xrange(30) ]
for i in xrange(1, 31):
    for j in xrange(1, 31):
        l[i][j] = l[i-1][j] + l[i][j-1]

print l
