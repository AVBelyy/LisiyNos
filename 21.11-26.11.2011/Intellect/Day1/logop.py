fi = open("logop.in")
fo = open("logop.out", "w")

op = fi.readline().strip()

if op == "NOT":
    bstr = fi.readline().strip()
    for x in map(lambda x: int(not int(x)), bstr):
        fo.write(str(x))
elif op == "AND":
    bstrA = fi.readline().strip()
    bstrB = fi.readline().strip()
    for x in map(lambda (x,y): int(x) & int(y), zip(bstrA, bstrB)):
        fo.write(str(x))
elif op == "OR":
    bstrA = fi.readline().strip()
    bstrB = fi.readline().strip()
    for x in map(lambda (x,y): int(x) | int(y), zip(bstrA, bstrB)):
        fo.write(str(x))
elif op == "XOR":
    bstrA = fi.readline().strip()
    bstrB = fi.readline().strip()
    for x in map(lambda (x,y): int(x) ^ int(y), zip(bstrA, bstrB)):
        fo.write(str(x))
fo.write("\n")
