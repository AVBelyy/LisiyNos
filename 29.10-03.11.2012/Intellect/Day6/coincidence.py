T = []

with open("coincidence.in") as f:
    n, m = map(int, f.readline().split())
    for x in xrange(n):
        s, r = f.readline().split()
        T.append([s, int(r)])
    for x in xrange(m):
