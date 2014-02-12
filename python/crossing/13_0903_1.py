#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import time

def crossing(lst):
	count = 0
	rest = [0]*len(lst)
	for i in xrange(len(lst)): 
		t = lst[i]
		count += sum(rest[:t])
		rest[t-1] = 1
		print t, rest, sum(rest[:t-1])
	return count

if __name__ == '__main__':
	first = time.clock()
	File = open(sys.argv[1], 'r')
	lst = []
	for i in File:
		lst.append(int(i))
	print lst
	print crossing(lst)
	print time.clock() - first 
