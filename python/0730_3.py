x = int(raw_input())
while x:
    x -= 1
    if x % 2 != 0:
        continue
    print x,
