import sys
import math

fact = [1]

for i in range(1, 101):
    fact.append(i * fact[len(fact)-1])

count = 0

for c in str(fact[len(fact)-1]):
    count += int(c)

print(count)
