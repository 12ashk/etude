#! /usr/bin/env python
# -*- coding utf-8 -*-

def euclid(m, n):
    while True:
        r = m % n
        if r == 0:
            return n
        m, n = n, r

if __name__ == '__main__':
    print euclid(int(raw_input('input number: ')), int(raw_input()))
