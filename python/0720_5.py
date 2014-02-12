a = ['catasdf', 'window', 'defenestrate']
for x in a[:]:
    if len(x) > 6: a.insert(0, x)
print a
