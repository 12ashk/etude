import sys
N = input()
command = raw_input()
button = ['A', 'B', 'X', 'Y']
ans = sys.maxint
for i in button:
    for j in button:
        for k in button:
            for l in button:
                if i+j == k+l: break
                n = 0
                c = 0
                while n < N-1:
                    if command[n]+command[n+1] == i+j:
                        n += 1
                    elif command[n]+command[n+1] == k+l:
                        n += 1
                    c, n = c+1, n+1
                if n < N: c+=1
                if ans > c:
                    ans = c
print ans
