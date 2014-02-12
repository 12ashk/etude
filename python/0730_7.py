y = int(raw_input())
x = y / 2
if y == 0 or y == 1:
    print y, 'is not prime'
else:
    while x > 1:
        if y % 2 == 0:
            print y, 'has factor', x
            break
        x -= 1
    else:
        print y, 'is prime'
