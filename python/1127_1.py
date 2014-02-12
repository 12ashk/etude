#! /usr/bin/env python
#! -*- codeing: utf-8 -*-
# Collaz Conjecture

def Collaz(n):
    if n % 2 == 0:
        n /= 2
        print n,
        if n == 1:
            return 1
        else:
            return Collaz(n)
    else:
        n = n * 3 + 1
        print n,
        return Collaz(n)

if __name__ == '__main__':
    Collaz(input('input number: '))
