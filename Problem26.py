import sys
import math

def LengthOfCycle(n):
    k = 1
    I = 0
    Q = [-1 for _ in range(2*n)]
    while(True):
        if k == 0:
            return 0
        if Q[k] != -1:
            return I-Q[k]
        Q[k] = I
        k *= 10
        k %= n
        I += 1

maxx = 0

for n in range(2, 1000):
    if(LengthOfCycle(n) > maxx):
        print(n, end = ' ')
        print(LengthOfCycle(n))
        maxx = LengthOfCycle(n)

print(maxx)
