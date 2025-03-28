#!/usr/bin/python3

MAX_ITER = 100

(n, m) = input().split(' ')

patterns = []

found = False

i = 1
while i <= MAX_ITER:
    if n == m:
        break

    for p in patterns:
        if p == n:
            found = True
            break
    if found:
        break

    patterns.append(n)

    counts = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    for j in range(len(n)):
        counts[int(n[j:j+1])] += 1

    nNew = ""
    for j in range(10):
        if counts[j] > 0:
            nNew = nNew + str(counts[j]) + str(j)
    n = nNew
    i += 1

if i > MAX_ITER:
    print("Can't use this input")
elif found:
    print("Does not appear")
else:
    print(i)
