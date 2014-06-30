H, W = map(int ,raw_input().split())
my_pieces = []
ene_pieces = []
for i in xrange(H):
    row = raw_input()
    my_pieces.append([])
    ene_pieces.append([])
    for j in xrange(W):
        if row[j] == 'o':
            my_pieces[-1].append(j)
        elif row[j] == 'x':
            ene_pieces[-1].append(j)

