N, M = map(int, raw_input().split())
matrix = [[0 for i in xrange(N)] for j in xrange(N)]
ans = 0
memo = []
for i in xrange(M):
    a, b = map(int, raw_input().split())
    matrix[a-1][b-1], matrix[b-1][a-1] = 1, 1

def check(j, lst):
    global matrix
    for h in lst:
        if matrix[h][j] != 1:
            return False
    return True

def dfs(i, lst):
    global matrix, ans, memo
    for j in xrange(i+1, len(matrix[i])):
        if matrix[i][j] == 1 and (not j in lst)\
                and check(j, lst):
            dfs(j, lst + [j])
    if len(lst) > ans:
        ans = len(lst)

for i in xrange(N):
    dfs(i, [i])
print ans
