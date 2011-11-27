with open("mouse.in") as f:
    a, b, c = map(int, f.readline().split())

open("mouse.out", "w").write("YES\n" if c <= min(a, b) else "NO\n")
