#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import time

def crossing(lst):
	count = 0
	rest = []
	for i in xrange(len(lst)):
		count += judge(i, lst[i], lst, rest)

	return count

def judge(pre_index, next_index, lst, rest):
	count = next_index - 1 - len([x for x in rest if x < next_index]) 
	rest.append(next_index)
	return count

if __name__ == '__main__':
	File = open(sys.argv[1], 'r')
	lst = []
	for i in File:
		lst.append(int(i))
	first = time.clock()
	print crossing(lst)
	print time.clock() - first 
