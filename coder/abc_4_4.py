def calc(n):
    n -= 1
    if n % 2 == 1: return (n/2+1)*(n/2) + n/2+1
    else: return (n/2+1)*n/2

r, g, b = map(int, raw_input().split())
if r < 50 and g < 50 and b < 50:
    s = calc(r)
    s += calc(g)
    s += calc(b)
    print s

