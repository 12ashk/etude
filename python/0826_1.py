def liput():
    seq1, seq2  = [], []
    for y in [seq1, seq2]:
        num = int(raw_input('enter number: '))
        for x in range(num):
            y.append(raw_input('enter list: '))
    print seq1, seq2
    res = []
    for x in seq1:
            if x in seq2:
                res.append(x)
    print res

liput()

