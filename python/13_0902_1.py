#! /usr/bin/env python
# -*- coding: utf-8 -*-

#data is time_data
#I suppose data is following.
#[[start_time, end_time], [start_time, end_time] ...]
#
#and I donot concern about comparing time
#I make imaginary compare function comp()
#I cannot program comp function
#because I donot know how time express.
#comp(first_time1, first_time2)
# if first_time1 is earlear than first_time2, 
# this function return True
# and if first_time2 is earlear than first_time1,
# return False

def max_counter(data):
	max_count = 0
	lst = []
	len(lst) == 0:
	count = 1
	lst[0] = data[0][0]
	lst = data[1:]

	for i, j in lst:#i is start_time, j is end_time
		count += 1
		if comp(lst[0], i):
			while(comp(lst[0], i)):
				lst.pop(0) #take very first element of lst
				count -= 1
		if count > max_count:
			max_count = count
		lst.append(j)
		lst.sort()#sort by time order
	return max_count
