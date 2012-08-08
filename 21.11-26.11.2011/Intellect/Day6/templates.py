import re

t1, t2 = open("templates.in").read().split()

def calc(t):
    return sum(map(lambda x: 0 if x  == "*" else 1, t))

def compile(t):
    return re.compile(t.replace("*", "[a-zA-Z]*").replace("?", "[a-zA-Z]?"))

print t1, t2
print calc(t1), calc(t2)
