#!/usr/bin/python3

# get n and m
(n,m) = list(map(int,input().split(' ')))

pages = []

# get page counts for each chapter
while len(pages) < n:
    line = list(map(int,input().split(' ')))
    pages += line

isCulminating = [True] * n
needToRead = [0] * n
prereq = [-1] * n

# get dependencies, build chains, mark chapters as not culminating
for i in range(m):
    (a,b) = list(map(int,input().split(' ')))

    a -= 1
    b -= 1

    prereq[b] = a

    isCulminating[a] = False

# initial best count is to read everything
best = 0
for p in pages:
    best += p

# get list of just culminating chapters
culminating = []
for c in range(n):
    if isCulminating[c]:
        culminating.append(c)

# track pages needing read
nPages = 0

# pick first culminating chapter
for i in range(len(culminating)):
    # trace back through dependency chain
    c = culminating[i]
    while c != -1:
        needToRead[c] += 1      # mark chapter as needing to be read
        nPages += pages[c]      # add pages to count
        c = prereq[c]           # move to previous chapter

    # pick second culminating chapter
    for j in range(i+1,len(culminating)):
        # trace back through dependency chain
        c = culminating[j]
        while c != -1:
            needToRead[c] += 1          # mark chapter
            if needToRead[c] == 1:      # don't add pages again if first pick also needs this chapter
                nPages += pages[c]
            c = prereq[c]               # move to previous chapter

        # check to see if this pair is better
        if nPages < best:
            best = nPages

        # go through the prereq chain and unmark for second pick
        c = culminating[j]
        while c != -1:
            needToRead[c] -= 1          # unmark the chapter
            if needToRead[c] == 0:      # if not needed by both culminating chapters, subtract from page count
                nPages -= pages[c]
            c = prereq[c]

    # go through the prereq chain and unmark for first pick
    c = culminating[i]
    while c != -1:
        needToRead[c] -= 1          # unmark the chapter
        nPages -= pages[c]
        c = prereq[c]

print(best)
