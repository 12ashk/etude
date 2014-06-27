import sys
way = ['N', 'NNE', 'NE', 'ENE', 'E', 'ESE', 'SE', 'SSE',
		'S', 'SSW', 'SW', 'WSW', 'W', 'WNW', 'NW', 'NNW', 'N']

vel = [25,155,335,545,795,1075,1385,1715,2075,2445,2845,3265, sys.maxint/10]

deg, dis = map(int, raw_input().split())

i = 0
while 112.5 + 225*i < deg:
    i+=1
print way[i]

j = 0
while dis*10 >= vel[j]*6:
	j += 1
print vel[j]
