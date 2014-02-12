#! /usr/bin/env python
#! -*- coding: utf-8 -*-

import sys
import time
import random

def calc():
    maxnum = 10
    n = 0
    t = time.clock()
    
    while n < 5:
        n1 = random.randint(1, maxnum)
        n2 = random.randint(1, maxnum)
        ans = str(n1 + n2)

        sys.stdout.write('%d + %d = ' % (n1, n2))
        s = sys.stdin.readline()
        if not s:
            break
        elif s[:-1] == ans:
            n += 1
        else:
            print 'wrong'
    else:
        print 'time : %.2f' % (time.clock() - t)

def calc2():
    n = 0
    maxnum = 10
    ops = (('+', lambda a, b: a + b), ('-', lambda a, b: a - b))

    while n < 5:
        op = random.choice(ops)
        n1 = random.randint(1, maxnum)
        n2 = random.randint(1, maxnum)
        ans = op[1](n1, n2)

        sys.stdout.write('%d %s %d = ' % (n1, op[0], n2))
        s = int(raw_input())
        if s == ans:
            n += 1
        elif not s:
            break
        else:
            print 'wrong'
    else:
        print 'time: %.2f' % (time.clock())

if __name__ == '__main__':
    calc2()

