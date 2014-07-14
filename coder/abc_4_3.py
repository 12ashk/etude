n = input() % 30
a = [str(i) for i in xrange(1, 7)]
for i in xrange(n):
    t = i % 5
    a[t], a[t+1] = a[t+1], a[t]
print ''.join(a)
