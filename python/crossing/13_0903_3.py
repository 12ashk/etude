#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import time

count = 0

def msort(lst):
	length = len(lst)
	if length == 1: return lst
	plst = msort(lst[:length/2])
	qlst = msort(lst[length/2:])
	return merge(plst, qlst)

def merge(plst, nlst):
	global count
	i, j = 0, 0
	lst = []
	plen = len(plst)
	nlen = len(nlst)
	while j < nlen and i < plen:
		if nlst[j] < plst[i]:
			lst.append(nlst[j])
			j += 1
			count += plen-i
		else:
			lst.append(plst[i])
			i += 1
	if i == plen: lst += nlst[j:]
	else: lst += plst[i:]
	return lst

if __name__ == '__main__':
	first = time.clock()
	File = open(sys.argv[1], 'r')
	lst = []
	for i in File: lst.append(int(i))
	msort(lst)
	print count
	print time.clock() - first 
	File.close()
