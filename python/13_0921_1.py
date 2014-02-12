#! /usr/bin/env python
# -*- coding: utf-8 -*-
import random

def q_sort(n):
	if len(n) <= 1:
		return n
	else:
		pivot = random.choice(n)
		now = []
		pre = []
		post = []
		for i in n:
			if i < pivot:
				pre.append(i)
			elif i > pivot:
				post.append(i)
			else:
				now.append(i)
		return q_sort(pre) + now + q_sort(post)

if __name__ == '__main__':
	lst = []
	for i in xrange(100):
		lst.append(random.randint(1, 100))
	print q_sort(lst)

