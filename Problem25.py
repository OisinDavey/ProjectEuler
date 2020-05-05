import math
import sys

Z = [[1, 1], [1, 0]]

def MatMult(A, B):
    H = len(A)
    W = len(B[0])
    Y = len(A[0])
    ans = [[0 for i in range(W)] for j in range(H)] 
    for i in range(0, H):
        for j in range(0, W):
            for k in range(0, Y):
                ans[i][j] += A[i][k]*B[k][j]
    return ans

def MatBinPow(Base, Expo):
    if Expo == 1:
        return Base
    Temp = MatBinPow(Base, Expo//2)
    Temp = MatMult(Temp, Temp)
    if(Expo%2):
        return MatMult(Base, Temp)
    else:
        return Temp

def Fib(n):
    n -= 1
    if(n == 0 or n == 1):
        return 1
    else:
        return MatBinPow(Z, n)[0][0]

l = 0
r = 10000

while l < r:
    mid = (l+r)//2
    if(len(str(Fib(mid))) < 1000):
        l = mid+1
    else:
        r = mid

print(r)
