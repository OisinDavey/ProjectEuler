import math
import sys

n, m = map(int, input().split())

ways = [[0 for _ in range(m)] for x in range(n + 1)]
sumn = [[0 for _ in range(m)] for x in range(n + 1)]

coins = [1, 2, 5, 10, 20, 50, 100, 200]

for i in range(n + 1):
    for j in range(m):
        if i == coins[j]:
            ways[i][j] = 1
        if i > coins[j]:
            ways[i][j] += sumn[i-coins[j]][j]
        
        sumn[i][j] += ways[i][j]
        
        if j > 0:
            sumn [i][j] += sumn[i][j-1]

print(sumn[n][m-1])
