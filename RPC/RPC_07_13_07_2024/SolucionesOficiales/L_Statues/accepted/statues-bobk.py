#!/usr/bin/python3

n,m = map(int,input().split(' '))

park = []

for r in range(n):
    park.append(list(map(int,input().split(' '))))

#print(park)

linear = []
for r in park:
    for c in r:
        if c != -1:
            linear.append(c)

linear.sort()
rev = []
for l in linear:
    rev.append(l)

rev.reverse()

#print('forward',linear)
#print('reverse',rev)

s = 0
count1 = 0
count2 = 0
for c in range(-n+1,m):
    r = n - 1
    c2 = c

    diag = []

    while r >= 0:
        if 0 <= c2 < m and park[r][c2] != -1:
            diag.append(park[r][c2])
        r -= 1
        c2 += 1

    sortedDiag = linear[s:s+len(diag)]
    rSortedDiag = rev[s:s+len(diag)]

    for d in diag:
        if d not in sortedDiag:
            count1 += 1
        if d not in rSortedDiag:
            count2 += 1

    s += len(diag)

s = 0
count3 = 0
count4 = 0
for c in range(m+n-1):
    r = n - 1
    c2 = c

    diag = []

    while r >= 0:
        if 0 <= c2 < m and park[r][c2] != -1:
            diag.append(park[r][c2])
        r -= 1
        c2 -= 1

    sortedDiag = linear[s:s + len(diag)]
    rSortedDiag = rev[s:s + len(diag)]

    for d in diag:
        if d not in sortedDiag:
            count3 += 1
        if d not in rSortedDiag:
            count4 += 1

    s += len(diag)

#print(count1,count2,count3,count4)

best = count1
if count2 < best:
    best = count2
if count3 < best:
    best = count3
if count4 < best:
    best = count4

print(best)
