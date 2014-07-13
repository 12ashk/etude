N, K = map(int ,raw_input().split())
lst = map(int ,raw_input().split())
lst.sort()
c = 0
for i in lst[-K:]: c = (c+i)/2.
print c
