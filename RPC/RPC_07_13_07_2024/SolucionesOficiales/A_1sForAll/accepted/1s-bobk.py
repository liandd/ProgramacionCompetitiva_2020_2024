#!/usr/bin/python3

cost = [-1] * 150001
cost[0] = 9999999
cost[1] = 1


def compute2(val):
    best = 99999999

    # multiplication
    f = 2
    while f * f <= val:
        if val % f == 0:
            c = cost[f] + cost[val // f]
            if c < best:
                best = c
        f += 1

    # concatenation
    if val > 9:
        c = cost[val%10] + cost[val//10]
        if c < best:
            best = c

    if val > 99:
        c = cost[val % 100] + cost[val // 100]
        if c < best and val % 100 > 9:
            best = c

    if val > 999:
        c = cost[val % 1000] + cost[val // 1000]
        if c < best and val % 1000 > 99:
            best = c

    if val > 9999:
        c = cost[val % 10000] + cost[val // 10000]
        if c < best and val % 10000 > 999:
            best = c

    # addition
    for ii in range(1,val//2+1):
        c = cost[ii] + cost[val-ii]
        if c < best:
            best = c

    cost[val] = best


n = int(input())

for i in range(2,n+1):
    compute2(i)

print(cost[n])

