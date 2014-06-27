ax, ay, bx, by, cx, cy = map(float, raw_input().split())
bx -= ax
cx -= ax
by -= ay
cy -= ay

print abs(bx*cy-by*cx)/2
