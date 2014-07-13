at = ['a','t','c','o','d','e','r', '@']
s, t = raw_input(), raw_input()
f = 1
for i, j in zip(s ,t):
    if i == '@':
        if not j in at: f = 0
    elif j == '@':
        if not i in at: f = 0
    elif i != j: f = 0
if f: print 'You can win'
else: print 'You will lose'
