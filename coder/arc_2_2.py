def check_leap(a):
    if a % 400 == 0 or (a % 100 != 0 and a % 4 == 0):
        return True
    return False

def check(y, m, d):
    if y/float(m) % d == 0:
        print "%d/%02d/%02d" % (y, m, d)
        return True
    return False

Y, M, D = map(float, raw_input().split('/'))
lst = [4, 6, 9, 11]
while not check(Y, M, D):
    if D > 27 and M == 2:
        if D == 28 and check_leap(Y): D+=1
        else: M, D = 3, 1
    elif D == 30 and M in lst:
        M, D = M+1, 1
    elif D > 30:
        if M == 12: Y, M, D = Y+1, 1, 1
        else: M, D = M+1, 1
    else: D+=1
