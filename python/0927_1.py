# FizzBuzz
a = 1
n = input("input a integer: ") + 1

if n < 1:
    n = 0
    print "input a integer more than 1"

while n > 300:
    n = 0
    print "input a integer less than 300"
while a < n:
    if a % 15 == 0:
        print "FizzBuzz"
    elif a % 3 == 0:
        print "Fizz"
    elif a % 5 == 0:
        print "Buzz"
    else:
        print a
    a = a + 1
