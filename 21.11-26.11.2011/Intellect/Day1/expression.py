lns = open("expression.in").read().split("\n")
fo = open("expression.out", "w")
for x in filter(None, lns):
    fo.write(str(int(eval(x.lower().replace("xor", "^"))))+"\n")
