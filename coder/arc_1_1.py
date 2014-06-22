N = input()
lst = raw_input()
maxans = [0, 0]
minans = [100, 0]

for i in xrange(1, 5):
    c = 0
    for j in xrange(len(lst)):
        if str(i) == lst[j]:
            c+=1
    if maxans[0] < c:
        maxans[0], maxans[1] = c, i
    if minans[0] > c:
        minans[0], minans[1] = c, i

print maxans[0], minans[0]
