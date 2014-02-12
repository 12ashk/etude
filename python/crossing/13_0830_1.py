#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import time

def crossing(lst):
	count = 0

	for i in xrange(len(lst)):
		count += judge(i, lst.index(i+1), lst)

	return count

def judge(pre_index, next_index, lst):
	count = 0
	if (len(lst) - pre_index) < next_index:
		for i in xrange(pre_index+1, len(lst)):
			if(next_index > lst.index(i)):
				count += 1
	else:
		for i in xrange(next_index):
			if(lst[i] > pre_index+1):
				count += 1
	return count

if __name__ == '__main__':
	File = open(sys.argv[1], 'r')
	lst = []
	for i in File:
		lst.append(int(i))
	first = time.clock()
	print crossing(lst)
	print time.clock() - first 
