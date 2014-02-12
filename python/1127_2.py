#! /usr/bin/env python
#! -*- coding: utf-8 -*-
# FizzBuzz

def FizzBuzz(n):
    for i in range(1, n+1):
        if i % 15 == 0:
            print 'FizzBuzz',
        elif i % 3 == 0:
            print '    Fizz',
        elif i % 5 == 0:
            print '    Buzz',
        else:
            print '%8d' % (i),

if __name__ == '__main__':
    FizzBuzz(input('input number: '))
