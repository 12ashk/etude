while 1:
    name = raw_input('Enter name: ')
    if name == 'stop':
        break
    age = raw_input('Enter age: ')
    print 'Hello', name, '=>', int(age) ** 2
