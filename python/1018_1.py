#! /usr/bin/env python
# -*- coding: utf-8 -*-

def testfunc(num):
    return num * num

if __name__ == '__main__':
    import doctest
    doctest.testmod()
