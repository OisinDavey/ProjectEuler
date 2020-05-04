import sys
import math

for i in range(0, 500):
    for j in range(0, 500):
        for k in range(0, 500):
            if i*i + j*j == k*k:
                if i + j + k == 1000:
                    print(i*j*k)
