#!/usr/bin/python3

n = int(input())

expected = []

while len(expected) < n:
    line = list(map(int,input().split(' ')))
    expected += line

stack = [-1] * (n + 1)
top = 0

bestAmount = -1
bestStart = -1
bestEnd = -1

for s in range(n):
    e = s + 1
    while e < n and expected[e] >= expected[s]:
        e += 1
    s2 = s - 1
    while s2 >= 0 and expected[s2] >= expected[s]:
        s2 -= 1
    s2 += 1

    if (e - s2) * expected[s] > bestAmount:
        bestAmount = (e - s2) * expected[s]
        bestStart = s2
        bestEnd = e - 1

print(bestStart + 1,bestEnd + 1,bestAmount)
