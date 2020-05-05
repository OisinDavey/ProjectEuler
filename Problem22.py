import sys
import math

f = open("p022_names.txt", "r")

content = f.read().split(',')

for i in range(0, len(content)):
    content[i] = content[i].replace('"', '')

content.sort()

count = 0

for i in range(0, len(content)):
    val = 0
    for c in content[i]:
        val += (1 + ord(c) - ord("A"))
    count += (i+1)*val

print(count)
