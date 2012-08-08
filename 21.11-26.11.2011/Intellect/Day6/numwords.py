s = open("numwords.in").read()
buf = ""
wc = 0

is_delim = lambda x: x in ("\n", " ", ".", ",", "!", "?")

for x in xrange(len(s)): 
    if (not (s[x-1].isalpha() and s[x+1].isalpha()) if s[x] == "-" else is_delim(s[x])):
        if buf:
            buf = ""
            wc += 1
    else:
        buf += s[x]

open("numwords.out", "w").write("%d\n" % wc)
