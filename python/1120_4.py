#! /usr/bin/env python
# -*- coding: utf-8 -*-

def quicksort(seq):
    if len(seq) < 1:
        return seq
    pivot = seq[0]
    left = []
    right = []
    for x in range(1, len(seq)):
        if seq[x] <= pivot:
            left.append(seq[x])
        else:
            right.append(seq[x])
    left = quicksort(left)
    right = quicksort(right)
    foo = [pivot]
    return left + foo + right

if __name__ == '__main__':
    import sys
    A = []
    for line in open(sys.argv[1], 'r'):
        linelist = line.split(' ')
        for i in linelist:
            if i.isdigit():
                A.append(int(i))
    A =  quicksort(A)
    for x in A:
        print x,
    print ''

