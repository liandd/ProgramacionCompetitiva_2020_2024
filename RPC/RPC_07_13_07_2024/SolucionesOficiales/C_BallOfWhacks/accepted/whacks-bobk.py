#!/usr/bin/python3

#
# these are one-position ccw rotations around each of the four corners of whack #1, plus a 180-degree
# rotation around whack #1
#

metaRotations = [
    #    1              6             11             16             21             26
    [ 0, 1,10,19,20, 6, 5,18,25,11, 2, 9,17,24,30,26,21,12, 7, 3, 4,16,29,27,13, 8,15,23,28,22,14], # 180
    [ 0, 2, 3, 4, 5, 1, 7, 8, 9,10, 6,13,14,15,16,17,18,19,20,11,12,22,23,24,25,21,27,28,29,30,26], # s corner
    [ 0, 6, 1,10,19,20, 2, 5,18,25,11, 3, 4, 9,17,24,30,26,21,12, 7, 8,16,29,27,13,14,15,23,28,22], # e corner
    [ 0,10, 5, 9,17,18, 1, 4,16,24,19, 2, 3, 8,15,23,29,30,25,20, 6, 7,14,28,26,11,12,13,22,27,21], # n corner
    [ 0, 5, 9,17,18,10, 4,16,24,19, 1, 8,15,23,29,30,25,20, 6, 2, 3,14,28,26,11, 7,13,22,27,21,12], # w corner
]

# rotations to bring whack #n into position 1
# each whack should have two rotations that work
# note: position 0 remains empty since there is no whack 0
rotations = []
for i in range(31):
    rotations.append([])


# compare two arrays
def compare(a,b):
    for j in range(len(a)):
        if a[j] != b[j]:
            return False

    return True


# rotate inVector using rVector to determine destination of each entry
def rotate(inVector,rVector):
    result = [0] * 31

    for j in range(len(inVector)):
        result[j] = inVector[rVector[j]]

    return result


# generate the rotation table via bfs
def generateRotations():
    queue = []

    current = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
               29, 30]

    queue.append(current)
    rotations[1].append(current)

    while len(queue) != 0:
        current = queue[0]
        queue = queue[1:]

        for rVec in metaRotations:
            tmp = rotate(current,rVec)

            match = False
            for r in rotations[tmp[1]]:
                match = match or compare(r,tmp)

            if not match:
                rotations[tmp[1]].append(tmp)

                queue.append(tmp)


# attempt to place a section of whacks into the ball
def place(used,whacks,wNum):

    # if all 3 sections have been placed, see if the entire ball is formed
    if wNum == 3:
        for j in range(1,31):
            if not used[j]:
                return False

        return True

    # try moving each missing whack position into position 1
    for j in range(1,31):
        if not used[j]:
            # rotate missing whack #j into position 1
            tmp = rotate(used,rotations[j][0])

            # try both rotations of the ball
            for k in [1,2]:
                # see if the next section can be added (all whacks missing)
                canAdd = True
                for whack in whacks[wNum]:
                    canAdd = canAdd and not tmp[whack]

                # if it can be added...
                if canAdd:
                    # add section to the ball
                    for whack in whacks[wNum]:
                        tmp[whack] = True

                    # try placing the next section
                    if place(tmp,whacks,wNum+1):
                        return True

                    # undo the placement
                    for whack in whacks[wNum]:
                        tmp[whack] = False

                # try 180-degree rotation
                tmp = rotate(tmp,metaRotations[0])

    # if all else fails
    return False


# main code starts here...

# generate the rotation lists
generateRotations()

# read the sections of whacks
w = []
for i in (1,2,3):
    w.append(list(map(int, input().split(' ')[1:])))

# start with an empty ball
existing = [False] * 31

# try to place the three sections
if place(existing,w,0):
    print("Yes")
else:
    print("No")
