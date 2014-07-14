N = input()
score = []
for i in xrange(N): score.append(raw_input())
p = 0
for i in xrange(N):
    for j in xrange(9):
        if score[i][j] == 'x': p += 1
        if score[i][j] == 'o':
            if i == 0 or score[i-1][j] != 'o': p += 1
print p 
