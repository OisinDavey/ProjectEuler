import sys
import math

def binpow(base, expo):
    if expo == 1:
        return base
    temp = binpow(base, expo//2)
    temp *= temp
    if expo % 2 == 1:
        temp *= base
    return temp

n = 101

L = set()

sumn = 0

for i in range(2, n):
    for j in range(2, n):
        temp = binpow(i, j)
        if not temp in L:
            sumn += 1
            L.add(temp)

print(sumn)
