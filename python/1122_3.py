#! /usr/bin/env python
#! -*- coding: utf-8 -*-

def mysqrt(s):
    x = s / 2.0
    last_x = 0.0

    while x != last_x:
        last_x = x
        x = (x + s / x) / 2.0

    return x

if __name__ == '__main__':
    print mysqrt(int(raw_input()))
