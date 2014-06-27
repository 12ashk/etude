N = input()
lst = []
for i in xrange(N):
    temp = map(int, raw_input().split('-'))
    if temp[0] % 5 == 0:
        pass
    elif temp[0] % 10 < 5:
        temp[0] -= (temp[0] % 10)
    else:
        temp[0] = temp[0] - (temp[0] % 10) + 5
    if temp[0] % 100 > 59:
        temp[0] = temp[0] - (temp[0] % 100) + 100
    if temp[1] % 5 == 0:
        pass
    elif temp[1] % 10 < 5:
        temp[1] = temp[1] - (temp[1] % 10) + 5
    else:
        temp[1] = temp[1] - (temp[1] % 10) + 10
    if temp[1] % 100 > 59:
        temp[1] = temp[1] - (temp[1] % 100) + 100
    lst.append(temp)
lst.sort()
ans = [[lst[0][0], lst[0][1]]]
if N > 1:
    for i in lst[1:]:
        if i[0] <= ans[-1][1] and i[1] > ans[-1][1]:
            ans[-1][1] = i[1]
        elif i[0] > ans[-1][1]:
            ans.append([i[0], i[1]])

for i in ans:
    print "%04d-%04d" % (i[0], i[1])
