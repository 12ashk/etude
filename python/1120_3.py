#! /usr/bin/env python
# -*- coding utf-8 -*-

def mult_table():
    for i in range(1, 10):
        for j in range(1, 10):
            print '%3d' % (i * j),
        print ""

if __name__ == '__main__':
    mult_table()

