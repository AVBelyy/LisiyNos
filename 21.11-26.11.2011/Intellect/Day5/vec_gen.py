res = []
for t in xrange(16):
    res.append([])

def gen(n):
    for x in xrange(2**n-1):
        X = bin(x)[2:]
        X = ("0"*(n - len(X)))+X
        flag = True
        for y in xrange(len(X)-1):
            if X[y] == X[y+1] == "1":
                flag = False
                break
        if flag: res[len(X)-1].append(X)

for t in xrange(16):
    gen(t+1)
print res
