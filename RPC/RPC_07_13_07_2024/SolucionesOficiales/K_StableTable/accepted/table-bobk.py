#!/usr/bin/python3

h,w = map(int,input().split(' '))

block = []
for r in range(h):
    line = list(map(int,input().split(' ')))
    block.append(line)

#print(block)

# find largest piece number
largest = 0
for r in block:
    for c in r:
        if c > largest:
            largest = c

# build adjacency lists up and down

upList = []
downList = []

for i in range(largest+1):
    upList.append([])
    downList.append([])

for r in range(h-1):
    for c in range(w):
        if block[r][c] != block[r+1][c]:
            if block[r+1][c] not in downList[block[r][c]]:
                downList[block[r][c]].append(block[r+1][c])
            if block[r][c] not in upList[block[r+1][c]]:
                upList[block[r+1][c]].append(block[r][c])

for c in block[h-1]:
    if 0 not in downList[c]:
        downList[c].append(0)
    if c not in upList[0]:
        upList[0].append(c)

top = []
for c in block[0]:
    if c not in top:
        top.append(c)

#print('down',downList)
#print('up',upList)
#print('top',top)

dist = [-1] * (largest + 1)
queue = [top[0]]
dist[top[0]] = 0

while len(queue) > 0:
    piece = queue[0]
    queue = queue[1:]

    for i in downList[piece]:
        if dist[i] == -1:
            dist[i] = dist[piece] + 1
            queue.append(i)

if len(top) == 1:
    print(dist[0])
else:
    dist2 = [-1] * (largest + 1)
    queue = [top[1]]
    dist2[top[1]] = 0

    while len(queue) > 0:
        piece = queue[0]
        queue = queue[1:]

        for i in downList[piece]:
            if dist2[i] == -1:
                dist2[i] = dist2[piece] + 1
                queue.append(i)

    upDist = [-1] * (largest + 1)
    queue = [0]
    upDist[0] = 0

    while len(queue) > 0:
        piece = queue[0]
        queue = queue[1:]

        for i in upList[piece]:
            if upDist[i] == -1:
                upDist[i] = upDist[piece] + 1
                queue.append(i)

    #print(dist)
    #print(dist2)
    #print(upDist)

    best = 999999
    for i in range(len(dist)):
        if dist[i] != -1 and dist2[i] != -1 and dist[i] + dist2[i] + upDist[i] < best:
            best = dist[i] + dist2[i] + upDist[i]

    print(best)