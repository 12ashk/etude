#! /usr/bin/env python
# -*- coding: utf-8 -*-

def divr(n):
    return [x for x in range(1, n+1) if n % x == 0]

def gcb(m, n):
    return [x for x in divr(m) if n % x == 0][-1]

def gcb2(m, n):
    if m > n:
        return [x for x in divr(n) if m % x == 0][-1]
    else:
        return [x for x in divr(m) if n % x == 0][-1]

def judgeprime(n):
    if n % 2 == 0:
        print '%d is not prime' % n
    elif len(divr(n/2)) == 2:
        print '%d is prime' % n
    else:
        print '%d is not prime' % n

def printn(lst):
    size = len(lst)
    for i in range(0, size, 10):
        for j in range(10):
            n = i + j
            if n < size and lst[n]:
                print '%3d' % n,
            else:
                print '   ',
        print

def sieve(size):
    primes = [True] * size
    primes[0] = False
    primes[1] = False

    printn(primes)
    for i in range(2, size):
        if primes[i]:
            print 'remove multiples of %d(except %d)'\
                    % (i, i)
            for j in range(i+i, size, i):
                primes[j] = False
            printn(primes)

if __name__ == '__main__':
    sieve(int(raw_input('input number: ')))
