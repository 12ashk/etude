# nabeatsu problem

def nabeatsu(n):
    return ["Aho" if i % 3 == 0 or '3' in str(i) else i for i in range(1, n + 1)]

print(nabeatsu(input('input integer: ')))
