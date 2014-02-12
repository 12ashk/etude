def fact(n):
    a = n
    while n > 0:
        a, n = a * n, n - 1
    return a

n = int (raw_input ("input number: "))
print n, '! is', fact(n)
