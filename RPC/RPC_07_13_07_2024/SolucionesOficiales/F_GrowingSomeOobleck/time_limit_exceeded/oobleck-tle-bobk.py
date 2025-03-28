#!/usr/bin/python3
from math import hypot, sqrt


def visit(ii):
    global circles
    global used
    global merging

    used[ii] = True

    merging.append(circles[ii])

    for jj in range(len(circles)):
        if used[jj]:
            continue
        dx = circles[ii][0]-circles[jj][0]
        dy = circles[ii][1]-circles[jj][1]
        d = sqrt(dx*dx+dy*dy) - circles[ii][2] - circles[jj][2]
        #print(ii,jj,d)
        if d <= 0:
            visit(jj)


circles = []

n = int(input())

tCur = 0

for i in range(n):
    circle = list(map(int,input().split(' ')))
    if circle[2] < 0:
        circle[2] = -circle[2]
    circles.append(circle)

# repeat until all circles merge
while len(circles) > 1:
    best = 999999
    #print(circles)

    # find the earliest time when circles meet
    for i in range(len(circles)-1):
        for j in range(i+1,len(circles)):
            ddx = circles[i][0] - circles[j][0]
            ddy = circles[i][1] - circles[j][1]
            dist = sqrt(ddx*ddx+ddy*ddy) - circles[i][2] - circles[j][2]
            # time when circles i and j touch
            t = dist / (circles[i][3] + circles[j][3])
            if t < best:
                best = t

    # if circles already touching then best time is now
    if best < 0:
        best = 0
    #best += 1e-8
    tCur += best
    #print('current t:',tCur,'   best delta-t:',best,'   current number of circles:',len(circles))

    # move forward until first touch
    for c in circles:
        c[2] += best * c[3]

    used = [False] * len(circles)

    tmp = []
    for i in range(len(circles)):
        if not used[i]:
            merging = []
            visit(i)
            x = 0
            y = 0
            r = 0
            s = 0
            #if len(merging) > 1:
            #    print('merge group:',merging)

            for c in merging:
                x += c[0]
                y += c[1]
                r += c[2] * c[2]
                if s < c[3]:
                    s = c[3]
#                s += c[3]

            tmp.append([x/len(merging),y/len(merging),sqrt(r),s])
            #print(merging)
            #print(tmp)

#    print(best)
    circles = tmp

print(circles[0][0],circles[0][1])
print(circles[0][2])
