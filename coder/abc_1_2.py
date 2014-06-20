a = int(raw_input())

if a < 0.1*1000:
	print '00'
elif 0.1*1000 <= a <= 5*1000:
	if a < 1000:
		print '0' + str(a/100)
	else:
		print a/100
elif 6*1000 <= a <= 30*1000:
	print a/1000 + 50
elif 35*1000 <= a <= 70*1000:
	print (a/1000-30)/5+80
else:
	print 89
