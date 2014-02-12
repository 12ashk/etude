# How many number?

import random
n = random.randint(1, 100)
m = 0
while m != n:
    m = input("how many number?: ")
    if m > n:
        print "more small"
    elif m < n:
        print "more large"
    else:
        pass

print "Congratulation!"
