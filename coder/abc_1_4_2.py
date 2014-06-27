N = input()
lst = [0 for i in xrange(24*12+1)]
for i in xrange(N):
    temp = map(int, raw_input().split('-'))
    temp[0] -= temp[0] % 5
    if temp[1] % 5 == 0:
        pass
    elif temp[1] % 10 < 5:
        temp[1] = temp[1] - (temp[1] % 10) + 5
    else:
        temp[1] = temp[1] - (temp[1] % 10) + 10
    if temp[1] % 100 == 60:
        temp[1] += 40
    lst[temp[0]/100*12+(temp[0]%100)/5] += 1
    lst[temp[1]/100*12+(temp[1]%100)/5] -= 1

s = 0
for i in xrange(1, len(lst)):
    lst[i] += lst[i-1]
    if lst[i-1] < 1 and lst[i] > 0:
        s = i
    elif lst[i-1] > 0 and lst[i] < 1:
        print "%02d%02d-%02d%02d" % (s/12, s%12*5, 
            i/12, i%12*5)
