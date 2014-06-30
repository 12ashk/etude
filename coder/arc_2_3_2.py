import sys
N = input()
command = raw_input()
button = ['A', 'B', 'X', 'Y']
ans = sys.maxint
for i in button:
    for j in button:
        for k in button:
            for l in button:
                t = command.replace(i+j, '*')
                t = t.replace(k+l, '*')
                if ans > len(t):
                    ans = len(t)
print ans
