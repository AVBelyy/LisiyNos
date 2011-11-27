N, m = map(int, open("choose.in").readline().split())
a = map(str, range(1, N+1))
z = range( m )

fo = open("choose.out", "w")

def Cnm( a, j ):
    if j <= m:
        for i in range(0,len(a) ):
            z[j-1] = a[i]
            _a = []
            for l in range(i+1,len(a) ):
                _a.append( a[l] )
            Cnm( _a, j+1 )
    else:
        fo.write(" ".join(z)+"\n")
        return

Cnm( a, 1 )
fo.close()
