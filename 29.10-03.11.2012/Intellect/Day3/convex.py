from __future__ import division

class GrahamScan:
    class Point:
        pos = None
        x   = None
        y   = None

        def __init__(self, (pos, (x, y))):
            self.pos, self.x, self.y = pos, x, y

        def __repr__(self):
            return "Point(%d, %d)" % (self.x, self.y)

    p = None
    v = None

    @staticmethod
    def cw(a, b, c):
        return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x)

    def __init__(self, points):
        self.v = map(GrahamScan.Point, enumerate(points))

    def scan(self):
        def compare(q1, q2):
            dy1 = q1.y-self.p.y
            dy2 = q2.y-self.p.y
            if   self.p == q1:         return -1
            elif self.p == q1:         return +1
            elif dy1 >= 0 and dy2 < 0: return -1
            elif dy2 >= 0 and dy1 < 0: return +1
            else: return GrahamScan.cw(self.p, q1, q2)

        discarded = []
        # find point with smallest y-coordinate
        self.p = min(self.v, key=lambda q: q.y)
        # sort points by polar angle with p
        self.v.sort(cmp=compare)
        # walk through array and remove items that are not on the convex hull
        a, b, c = 0, 1, 2
        while c < len(self.v):
            if GrahamScan.cw(self.v[a], self.v[b], self.v[c]) < 0:
                a, b, c = a+1, b+1, c+1
            else:
                discarded.append(self.v[b])
                del self.v[b]
                print self.v, a, b, c
        return self.v

vertices = map(lambda x: map(int, x.split()), open("convex.in"))[1:]
hull = GrahamScan(vertices).scan()
open("convex.out", "w").write("\n".join([str(len(hull))]+map(lambda p: "%s %s" % (p.x, p.y), hull)))
