#!/usr/bin/python3

def choose(nn, k):
    if k > nn:
        return 0

    ans = 1
    num = nn
    den = 1

    while den <= k:
        ans = (ans * num) // den
        num -= 1
        den += 1

    return ans


def try15(cc, s):
    temp = 0
    if s == 0:      # achieved our sum
        # print("yes", cc, nPerRank)
        return 2
    if cc > 9:      # no more cards to try
        return 0
    ii = 0
    while ii <= nPerRank[cc] and ii * (1 + cc) <= s:
        temp += choose(nPerRank[cc], ii) * try15(cc+1, s-ii*(1+cc))
        # print(cc, temp)
        ii += 1

    return temp


nCards = int(input())

cards = []
while len(cards) < nCards:
    cards.extend(input().split(' '))
    # print(cards)

# print(cards)

nPerRank = [0] * 13

for c in cards:
    if c == 'A':
        nPerRank[0] += 1
    elif c == 'T':
        nPerRank[9] += 1
    elif c == 'J':
        nPerRank[10] += 1
    elif c == 'Q':
        nPerRank[11] += 1
    elif c == 'K':
        nPerRank[12] += 1
    else:
        nPerRank[ord(c)-ord('1')] += 1

score = 0

# pairs
for n in nPerRank:
    if n > 1:
        score += n * (n - 1)

# print("pairs", score)

# runs
i = 0   # method B
while i <= 10:
    # for i in range(11):    # method A
    if nPerRank[i] > 0 and nPerRank[i+1] > 0 and nPerRank[i+2] > 0:
        tmp = 1
        j = i
        runLen = 0
        while j < 13 and nPerRank[j] > 0:
            tmp *= nPerRank[j]
            j += 1
            runLen += 1
        score += tmp * runLen
        i += runLen                 # more method B
    else:
        i += 1

# print("runs", score)

# 15s
nPerRank[9] += nPerRank[10] + nPerRank[11] + nPerRank[12]
score += try15(0, 15)

print(score)
