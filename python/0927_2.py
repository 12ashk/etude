# prime judgement

def prime_check(x):
    if x < 2:
        return 0
    if x == 2:
        return 1
    if x % 2 == 0:
        return 0

    a = 3
    while a ** 2 <= x:
        if x % a == 0:
            return 0
        a = a + 2

    return 1

x = input("input number: ")
if prime_check(x) == 1:
    print "%d is a prime" % x
if prime_check(x) == 0:
    print "%d is not a prime" % x
exit()
