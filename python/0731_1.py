i = int(raw_input())
L = []
for x in range(i):
    L.append(int(raw_input()))

for i in range(len(L)):
    L[i] += 1 
print L

i = 0
while i < len(L):
    L[i] += 1
    i += 1
print L

L = [x + 1 for x in L]
print L
