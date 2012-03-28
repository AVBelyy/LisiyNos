a, b, x1, x2 = map(float, open("valdiff.in").read().split())
ans = (x1-x2)*(a*b+1)/b
open("valdiff.out", "w").write("%.5f\n" % ans)
