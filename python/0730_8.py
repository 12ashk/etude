x = raw_input()
while x:
    if match(x[0]):
        print 'Ni'
        break
    x = x[1:]
else:
    print 'Not found'
