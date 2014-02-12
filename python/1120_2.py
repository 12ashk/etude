#! /usr/bin/env python
# -*- coding utf-8 -*-

def qsort(A, p, q):
    if p < q:
        r = partition(A, p, q)
        qsort(A, p, r)
        qsort(A, r+1, q)

def partition(A, p, q):
    pivot = A[p]
    i = p
    while i != q+1 and A[i] == pivot:
        if A[i] > pivot:
            pivot = A[i]
            break
        i += 1

    if i == q+1:
        return p
    i = p
    j = q
    while i < j:
        while i < j and A[j] >= pivot:
            j -= 1

        while i < j and A[i] < pivot:
            i += 1

        if i < j:
            A[i], A[j] = A[j], A[i]

    if i == j and A[i] < pivot:
        return i
    else:
        return j

if __name__ == '__main__':
    import sys
    A = []
    for line in open(sys.argv[1], 'r'):
        linelist = line.split(' ')
        for i in linelist:
            if i.isdigit():
                A.append(int(i))
        
    inum = len(A)
    print inum, A[inum-1]
    qsort(A, 0, inum-1)
    for x in A:
        print x,
    print ''
