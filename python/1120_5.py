#! /usr/bin/env python
# -*- coding: utf-8 -*-

def qsort(lst):
    if len(lst) == 0:
        return lst
    else:
        x, xs = lst[0], lst[1:]
        return qsort([a for a in xs if a < x]) + [x] + qsort([a for a in xs if a >= x])

if __name__ == '__main__':
    import sys
    A = []
    for line in open(sys.argv[1], 'r'):
        linelist = line.split(' ')
        for x in linelist:
            if x.isdigit():
                A.append(x)
    for x in qsort(A):
        print x,
    print ''
