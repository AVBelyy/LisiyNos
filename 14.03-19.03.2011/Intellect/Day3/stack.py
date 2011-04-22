#!/usr/bin/env python

with open("stack.in", "r") as fi:
    fi.readline()
    commands = [ln.split() for ln in fi.readlines()]

stack = []
result = []

for command in commands:
    if command[0] == 'PUSH':
        stack.append(int(command[1]))
        result.append(str(stack))
    elif command[0] == 'POP':
        result.append('{0} {1}'.format(stack.pop(), stack))

with open('stack.out', 'w') as fo:
    fo.write('\n'.join(result))
    fo.write('\n')
