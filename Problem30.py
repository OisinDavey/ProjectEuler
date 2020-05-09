import math
import sys

S = 0

for i in range(2, 1000001):
    s = str(i)
    sumn = 0
    for c in s:
        sumn += int(c)**4
    if sumn == i:
        S += i

print(S)
