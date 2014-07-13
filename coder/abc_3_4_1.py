from math import *
R, C = map(int, raw_input().split())
X, Y = map(int, raw_input().split())
L, D = map(int, raw_input().split())
n = (R-X+1)*(C-Y+1)
print n*factorial(X*Y)/(factorial(X*Y-L)*factorial(L))%1000000007
