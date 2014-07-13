 import sys
lst, large, small = [], [], []
memo = []
N = input()
for i in xrange(N):
    a, b, c = raw_input().split()
    lst.append([a, float(b), c])
    large.append(a), small.append(c)
def search(i, n):
    global lst
    t = []
    for j in xrange(N):
        if lst[i][2] == lst[j][0]:
            t.append([j, lst[j][1]])
    if t:
        t.sort(key=lambda x: x[0], reverse=True)
        return search(t[0][0], n*t[0][1])
    else: return [n, lst[i][2]]
for i in xrange(N):
    if not lst[i][0] in small and lst[i][2] in large:
        memo.append([lst[i][0]] + search(i, lst[i][1]))
if memo:
    memo.sort(key=lambda x: x[1], reverse=True)
    if int(memo[0][1]) == memo[0][1]:
        print '1'+memo[0][0]+'='+str(int(memo[0][1]))+lst[0][2]
    else:
        print '1'+memo[0][0]+'='+str(memo[0][1])+lst[0][2]
else: print '1'+lst[0][0]+'='+str(lst[0][1])+lst[0][2]
