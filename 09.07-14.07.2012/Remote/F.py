def solver(A, f):
    for x in xrange(1, len(A)-1):
        s = f[x-1:x+2]
        d = A[x]-s.count(1)
        if   d == -1:
            return # unsolvable
        elif d == 0:
            if f[x+1] == -1:
                f[x+1] = 0
        elif d == 1:
            if f[x+1] == -1:
                f[x+1] = 1
            else:
                return
        else:
            return
    if A[0] == f[:2].count(1) and A[-1] == f[-2:].count(1):
        return f
    else:
        return

def uniq(f):
    f_ = []
    for x in f:
        if x not in f_:
            f_.append(x)
    return f_

def minesweeper(A, F):
    p1, p2 = [], []
    case = lambda x: [ [[0, 0]], [[0, 1], [1, 0]], \
                       [[1, 1]], None ][x]

    cells = case(A[0])
    if not cells: return []
    for c in cells:
        f = F[:]
        f[:2] = c
        p1.append(f)
    # check the last cell
    cells = case(A[-1])
    if not cells: return []
    for c in cells:
        for p_ in p1:
            p = p_[:]
            p[-2:] = c
            p2.append(p)
    # solve
    return filter(None, uniq(map(lambda l: solver(A, l), p2)))

L = open("F.IN").readlines()
N = int(L[0])
A = map(int, L[1].split()[:N])
F = [-1]*N

O = minesweeper(A, F)
open("F.OUT", "w").write("\n".join([str(len(O))]+sorted(map(lambda f: "".join(map(lambda x: ["_", "#"][x][:len(A)], f)), O))))
