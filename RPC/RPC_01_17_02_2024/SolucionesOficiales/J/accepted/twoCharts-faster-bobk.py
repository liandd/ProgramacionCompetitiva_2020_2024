#!/usr/bin/python3

depList = []
supList = []
#import sys

#sys.setrecursionlimit(10000)
def search(dep):
    for i in range(len(depList)):
        if dep == depList[i]:
            return i

    i = len(depList)
    depList.append(dep)
    supList.append([-1, -1, False, False])
    return i


def parse(ii, parent, chart, line):
    global listA
    global listB
    global listC
    global listD
    global listE
    # skip lead whitespace
    while ii < len(line) and line[ii:ii+1].isspace():
        ii += 1

    # get supervisor dept
    jj = ii
    while jj < len(line) and line[ii:jj+1].isdigit():
        jj += 1
#    sup = search(int(line[ii:jj]))
    sup = int(line[ii:jj])
    if chart == 0:
        listA[sup] = parent
        listC[sup] = True
    else:
        listB[sup] = parent
        listD[sup] = True
    listE[sup] = True
    
#    supList[sup][chart] = parent
#    supList[sup][chart + 2] = True
#    supList[sup][4] = True

    ii = jj

    # loop over supervised departments
    while ii < len(line):
        # print(ii, len(line))

        # lookahead
        while ii < len(line) and line[ii:ii+1].isspace():
            ii += 1

        # print("foo")
        # EOL or ) = done
        if ii == len(line) or line[ii:ii+1] == ')':
            return ii

        # ( = recurse, start by skipping over (
        ii += 1

        # print("bar")
        ii = parse(ii, sup, chart, line)

        # print("baz")
        # skip over )
        while line[ii:ii+1] != ')':
            ii += 1
        ii += 1
        # print("done", ii)

    # print("ret", ii, len(line), parent)
    # all done
    return ii
    

#supList = []
#for i in range(1000001):
#    supList.append([-1, -1, False, False, False])
listA = [-1] * 1000001
listB = [-1] * 1000001
listC = [False] * 1000001
listD = [False] * 1000001
listE = [False] * 1000001
#supList = [ [-1, -1, False, False, False] for _ in range(1000001)]

chart0 = input()
parse(0, -1, 0, chart0)

chart1 = input()
parse(0, -1, 1, chart1)

#print(depList, supList)
okay = True
#for s in supList:
#    if s[4] and (s[0] != s[1] or not s[2] or not s[3]):
#        okay = False
for i in range(1000001):
    if listE[i] and (listA[i] != listB[i] or not listC[i] or not listD[i]):
        okay = False

if okay:
    print("Yes")
else:
    print("No")
