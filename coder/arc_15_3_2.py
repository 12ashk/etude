N = input()
lst, memo = [], []
for i in xrange(N):
    lst.append(raw_input().split())
def search(n):
    global N, lst, memo
    for i in xrange(len(memo)):
        if memo[i][0] == lst[n][0]:
            return [memo[i][1], memo[i][2]]
        if memo[i][0] == lst[n][2]:
            t = int(lst[n][1])*memo[i][1]
            memo.append([lst[n][0], t, memo[i][2], memo[i][3]+1])
            return [t, memo[i][2], memo[i][3]]

    t = []
    for i in xrange(N):
        if lst[n][2] == lst[i][0]:
            t.append(search(i))
    t.sort(reverse=True)
    if t:
        memo.append([lst[n][0], int(lst[n][1])*t[0][0], t[0][1], t[0][2]])
        return [int(lst[n][1])*t[0][0], t[0][1], t[0][2]+1]
    else: 
        memo.append([lst[n][0], int(lst[n][1]), lst[n][2], 0])
        return [int(lst[n][1]), lst[n][2], 0]

for i in xrange(N):
    search(i)
memo.sort(key=lambda x:x[3], reverse=True)
print '1'+memo[0][0]+'='+str(memo[0][1])+memo[0][2]
