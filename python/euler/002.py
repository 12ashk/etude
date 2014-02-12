#! /usr/bin/env python
# -*- coding: utf-8 -*-
import time

if __name__ == '__main__':
	first = time.clock()
	i, j = 0, 1
	num = 0
	while(j <= 4000000):
		if j % 2 == 0:
			num += j
		i, j = j, i+j
	print num, 'time: ', time.clock() - first
