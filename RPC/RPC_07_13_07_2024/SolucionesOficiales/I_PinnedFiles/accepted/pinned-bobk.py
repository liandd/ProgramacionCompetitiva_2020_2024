#!/usr/bin/python3

# get the initial pinned and unpinned lists
(p,u) = list(map(int,input().split(' ')))

vals = list(map(int,input().split(' ')))

pinned = vals[:p]
unpinned = vals[p:]
unpinned.reverse()

# get the desired pinned and unpinned lists
(pFinal,uFinal) = list(map(int,input().split(' ')))

valsFinal = list(map(int,input().split(' ')))

pinnedFinal = valsFinal[:pFinal]
unpinnedFinal = valsFinal[pFinal:]
unpinnedFinal.reverse()

nClicks = 0

# loop over all final pinned

processed = []
for i in range(len(pinnedFinal)):
    # is it pinned?
    isPinned = False
    mustDouble = False
    for j in range(len(pinned)):
        if pinned[j] == pinnedFinal[i]:
            isPinned = True
            # is it in front of any elements already pinned?
            for k in range(j+1,len(pinned)):
                if pinned[k] in processed:
                    mustDouble = True

    # if not pinned, must click once to add to pinned list
    if not isPinned:
        nClicks += 1

        # remove from unpinned list
        unpinned.remove(pinnedFinal[i])

        # add to pinned list
        pinned.append(pinnedFinal[i])

    # otherwise, if it's in front of other processed values, must double click to remove and append
    elif mustDouble:
        nClicks += 2

        # remove from pinned list
        pinned.remove(pinnedFinal[i])

        # add to pinned list
        pinned.append(pinnedFinal[i])

    # add to processed list
    processed.append(pinnedFinal[i])

# loop over all final unpinned

processed = []
for i in range(len(unpinnedFinal)):
    # is it unpinned?
    isUnpinned = False
    mustDouble = False
    for j in range(len(unpinned)):
        if unpinned[j] == unpinnedFinal[i]:
            isUnpinned = True
            # is it in front of any elements already unpinned?
            for k in range(j+1,len(unpinned)):
                if unpinned[k] in processed:
                    mustDouble = True

    # if not pinned, must click once to add to pinned list
    if not isUnpinned:
        nClicks += 1

        # remove from pinned list
        pinned.remove(unpinnedFinal[i])

        # add to unpinned list
        unpinned.append(unpinnedFinal[i])

    # otherwise, if it's in front of other processed values, must double click to remove and append
    elif mustDouble:
        nClicks += 2

        # remove from uhpinned list
        unpinned.remove(unpinnedFinal[i])

        # add to unpinned list
        unpinned.append(unpinnedFinal[i])

    # add to processed list
    processed.append(unpinnedFinal[i])

print(nClicks)
#print(pinned,unpinned)
#print(pinnedFinal,unpinnedFinal)
