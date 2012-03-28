f = map(float,open("valsum.in").read().split("\n")[1].split(" "))
ans = sum(f) + sum(map(lambda x: 1/x, f))
open("valsum.out", "w").write("%.9f\n" % ans)
