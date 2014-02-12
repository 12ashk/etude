n = int(raw_input("input number: ")) 
a = n
while n > 0:
    a, n = a * n, n -1
print a
