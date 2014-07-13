lst = [0, 0, 0, 0, 0, 0]
N = input()
for i in xrange(N):
    h, l = map(float, raw_input().split())
    if h >= 35: lst[0]+=1
    elif h >= 30: lst[1]+=1
    elif h >= 25: lst[2]+=1
    if l >= 25: lst[3]+=1
    if h < 0: lst[5]+=1
    elif l < 0: lst[4]+=1
print ' '.join(map(str, lst))
