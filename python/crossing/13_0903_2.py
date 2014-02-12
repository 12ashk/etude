#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import random
import time

def crossing(lst):
	print qsort(lst)

def qsort(lst):
	if len(lst) <= 1:
		return lst
	elif len(lst) == 2:
		if lst[0] < lst[1]:
			return lst
		else:
			return [lst[1], lst[0]]
	else:
		pivot = random.choice(lst)
		p_lst = []
		n_lst = []
		for i in lst:
			if i < pivot:
				p_lst.append(i)
			elif i > pivot:
				n_lst.append(i)
		return qsort(p_lst) + [pivot] + qsort(n_lst)

if __name__ == '__main__':
	first = time.clock()
	File = open(sys.argv[1], 'r')
	lst = []
	for i in File:
		lst.append(int(i))
	print lst
	crossing(lst)
	print time.clock() - first 
