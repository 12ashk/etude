def sum(seq):
    def add(x, y): return x + y
    return  reduce(add, seq, 0)

i, j = int(raw_input("")), int(raw_input("->"))

print sum(range(i, j))
