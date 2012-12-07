import re

def is_letter(ch):
    if (ch >= "a" and ch <= "z") or (ch >= "A" and ch <= "Z"): return True
    else: return False

VAR = ["`"]

def nextvar():
    global VAR
    flag = True
    for x in xrange(len(VAR)-1, -1, -1):
        if VAR[x] == "z":
            flag = True
            VAR[x] = "a"
        else:
            VAR[x] = chr(ord(VAR[x])+1)
            flag = False
            break
    if flag: VAR.insert(0, "a")
    return "".join(VAR)

program = open("obfuscat.in").read()
indent, x, oneline, instr = 0, 0, False, False
program2, program3, program4 = "", "", ""

while x < len(program):
    if program[x:x+2] == "\\\"" and instr and not indent and not oneline:
        program2 += "\\\""
        x += 2
        continue
    if program[x] == "\"" and not indent and not oneline:
        instr = not instr
    if not instr:
        if program[x:x+2] == "/*" and not oneline:
            indent += 1
            x += 1
        elif program[x:x+2] == "*/" and not oneline and indent > 0:
            indent -= 1
            x += 1
            if not indent: program2 += " "
        elif not indent:
            if program[x:x+2] == "//":
                oneline = True
            elif program[x] == "\n" and oneline:
                oneline = False
            if not oneline:
                if program[x] == "\n":
                    program2 += " "
                else:
                    program2 += program[x]
    else:
        program2 += program[x]
    x += 1

x, instr = 0, False
r0, r1 = re.compile("read [a-z]", re.IGNORECASE), re.compile("print [a-z]", re.IGNORECASE)
while x < len(program2):
    if program2[x:x+2] == "\\\"" and instr:
        program3 += "\\\""
        x += 2
        continue
    if program2[x] == "\"":
        instr = not instr
    if not instr:
        if program2[x] == " ":
            if r0.match(program2[x-4:x+3]) \
            or r1.match(program2[x-5:x+2]   ):
                program3 += program2[x]
        else:
            program3 += program2[x]
    else:
        program3 += program2[x]
    x += 1

words, x, instr = [["", 0]], 0, False
while x < len(program3):
    if program3[x:x+2] == "\\\"" and instr:
        x += 2
        continue
    if program3[x] == "\"":
        instr = not instr
    if not instr:
        if is_letter(program3[x]):
            if words[-1] == ["", 0]:
                words[-1][1] = x
            words[-1][0] += program3[x]
        elif program3[x] == "(" and words[-1][0]:
            words[-1][0] += "("
            words.append(["", 0])
        else:
            words.append(["", 0])
    x += 1

words = filter(lambda x: x != ["", 0], words)
varz, d = {}, 0

for w, off in words:
    w = w.lower()
    KW = program3[off+d:off+d+255].lower()
    if KW[:8] == "program{":
        continue
    if KW[:8] == "program(":
        continue
    elif KW[:3] == "if(":
        continue
    elif KW[:5] == "read(":
        continue
    elif KW[:5] == "read ":
        continue
    elif KW[:6] == "print(":
        continue
    elif KW[:6] == "print\"":
        continue
    elif re.match("^print[0-9]+", KW) or re.match("^print\s[a-z]+", KW):
        continue
    if w not in varz:
        varz[w] = nextvar() if w[-1] != "(" else w
    v = varz[w]
    program3 = program3[:off+d]+v+program3[off+len(w)+d:]
    d -= len(w)-len(v)

program4 = ""

open("obfuscat.out", "w").write(program3)