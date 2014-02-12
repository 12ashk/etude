#! /use/bin/env python
#! -*- utf-8 -*-

import math

def isprime(n, primes):
    for i in range(int(math.sqrt(n))):
        if n % primes[i] == 0:
            return False
    return True

def primes(n):
    prms = [2]
    for i in range(3, n+1, 2):
        if isprime(i, prms):
            prms.append(i)
    return prms

def factorization(n):
    prm = primes(n)
    fact = []
    for i in range(len(prm)):
        if n % prm[i] == 0:
            while not n % prm[i]:
                fact.append(prm[i])
                n /= prm[i]
    return fact

if __name__ == '__main__':
    print factorization(int(raw_input('input number: ')))
