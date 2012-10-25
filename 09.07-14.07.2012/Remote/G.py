def regexp(s):
    s = s.strip().replace("!", "???")
    l = len(s)
    for x in xrange(l):
        if "*" in (s[x], s[l-x-1]):
            return "YES"
        elif s[x] == "?" or s[l-x-1] == "?":
            pass
        elif s[x] != s[l-x-1]:
            return "NO"
    return "YES"

open("G.OUT", "w").write("\n".join(map(regexp, open("G.IN"))[1:]))
