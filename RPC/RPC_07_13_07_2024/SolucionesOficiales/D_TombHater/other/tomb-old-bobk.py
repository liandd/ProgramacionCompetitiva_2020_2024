#!/usr/bin/python3

# dir row col word pos


def enqueue(val):
    global queue
    global qcap
    global qcount
    global qtail

    if qcount == qcap:
        print("queue full")
        return

    qcount += 1
    queue[qtail] = val
    qtail = (qtail + 1) % qcap


def dequeue():
    global queue
    global qhead
    global qcount

    qcount -= 1
    qhead = (qhead + 1) % qcap

    return queue[qhead]


def check(ddir,row,col,word,pos,cost):
    global dist
    global grid
    global queue
    global glyphs

#    print(ddir,row,col,word,pos,cost)

    # if at end of word, look for start of next word
    if pos == len(glyphs[word]):
        for ii in range(len(glyphs)):
            if grid[row][col] == glyphs[ii][0] and dist[ddir][row][col][ii][0] == -1:
                dist[ddir][row][col][ii][0] = cost + 1
#                queue.append([ddir,row,col,ii,0])
                enqueue([ddir,row,col,ii,0])

    # otherwise, look for next char in word
    else:
        if grid[row][col] == glyphs[word][pos] and dist[ddir][row][col][word][pos] == -1:
            dist[ddir][row][col][word][pos] = cost + 1
            #queue.append([ddir,row,col,word,pos])
            enqueue([ddir,row,col,word,pos])


size = 50
qcap = 1000000

dist = [[[[[-1] * size for ii in range(size)] for jj in range(size)] for kk in range(size)] for ll in range(3)]

#print(len(dist))

m,n,k = map(int,input().split(' '))

grid = []
for i in range(m):
    line = input().split(' ')
    grid.append(line)

glyphs = []
for i in range(k):
    glyphs.append(input())

queue = []
for i in range(qcap):
    queue.append([0,0,0,0,0])
qhead = qcap - 1
qtail = 0
qcount = 0

# initial steps
for i in range(n):
    for j in range(k):
        if grid[0][i] == glyphs[j][0]:
            dist[1][0][i][j][0] = 1
            #queue.append([1,0,i,j,0])
            enqueue([1,0,i,j,0])

#print(queue)

# process all queue entries
while qcount > 0:
    #print(len(queue))
    #print(qhead,qtail,queue)
    #cell = queue[0]
    #queue = queue[1:]
    cell = dequeue()

    # process left
    if cell[0] != 2 and cell[2] > 0: # left
        check(0,cell[1],cell[2]-1,cell[3],cell[4]+1,dist[cell[0]][cell[1]][cell[2]][cell[3]][cell[4]])
    # process down
    if cell[1] < m - 1:
        check(1,cell[1]+1,cell[2],cell[3],cell[4]+1,dist[cell[0]][cell[1]][cell[2]][cell[3]][cell[4]])
    # process right
    if cell[0] != 0 and cell[2] < n - 1:
        check(2,cell[1],cell[2]+1,cell[3],cell[4]+1,dist[cell[0]][cell[1]][cell[2]][cell[3]][cell[4]])

#    print(queue)

best = 99999
for i in range(n):
    for j in range(k):
        for d in range(3):
            val = dist[d][m-1][i][j][len(glyphs[j])-1]
            if -1 < val < best:
                best = val

if best == 99999:
    print('impossible')
else:
    print(best)

#print(dist)