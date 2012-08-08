ln = open("brackets.in").read()
f = open("brackets.out", "w")
stack, count = [], [0, 0, 0]

for ch in ln:
    if ch == "(":
        count[0] += 1
        stack.append(ch)
    if ch == "[":
        count[1] += 1
        stack.append(ch)
    if ch == "{":
        count[2] += 1
        stack.append(ch)
    try:
        if ch == ")":
            count[0] -= 1
            if stack.pop() != "(": raise IndexError
        if ch == "]":
            count[1] -= 1
            if stack.pop() != "[": raise IndexError
        if ch == "}":
            count[2] -= 1
            if stack.pop() != "{": raise IndexError
    except:
        f.write("NO\n")
        f.close()
        exit(0)

f.write("YES\n" if count == [0, 0, 0] else "NO\n")
f.close()
