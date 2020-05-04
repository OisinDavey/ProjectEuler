import math
import sys

maxx = 1 

for i in range(0, 1000):
    for j in range(i, 1000):
        n = str(i * j)
        b = True
        for x in range(0, len(n)//2):
            if n[x] != n[len(n) - x -1]:
                b = False
                break
        if b and int(n) > maxx:
            maxx = int(n)
            print(n, end=' ')
            print(i, end=' ')
            print(j)
