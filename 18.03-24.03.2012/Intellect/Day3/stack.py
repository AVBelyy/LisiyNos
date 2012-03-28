fi = open("queue.in")
fo = open("queue.out", "w")
n = int(fi.readline())
s = []
for i in xrange(n):
    cmd = fi.readline()
    if cmd == "GET\n":
        fo.write("%s %s\n" % (s.pop(), s))
    else:
        cmd, arg = cmd.split(" ")
        s.insert(0, int(arg))
        fo.write("%s\n" % s)
fo.close()    
