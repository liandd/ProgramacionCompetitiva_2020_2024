#!/usr/bin/python3

BASES = "ATGC"

dnaString = input()

nQueries = int(input())

current = [0, 0, 0, 0]

counts = [current.copy()]

#    if letter == 'A':
#        current[0] += 1
#    if letter == 'T':
#        current[1] += 1
#    if letter == 'G':
#        current[2] += 1
#    if letter == 'C':
#        current[3] += 1

for i in range(nQueries):
    (start, end) = map(int, input().split(' '))

    order = [0, 1, 2, 3]
    current = [0, 0, 0, 0]

    for j in range(start-1, end):
        current[BASES.find(dnaString[j:j + 1])] += 1

    if current[order[0]] < current[order[1]] or (current[order[0]] == current[order[1]] and order[1] < order[0]):
        (order[0], order[1]) = (order[1], order[0])
    if current[order[2]] < current[order[3]] or (current[order[2]] == current[order[3]] and order[3] < order[2]):
        (order[2], order[3]) = (order[3], order[2])
    if current[order[0]] < current[order[2]] or (current[order[0]] == current[order[2]] and order[2] < order[0]):
        (order[0], order[2]) = (order[2], order[0])
    if current[order[1]] < current[order[3]] or (current[order[1]] == current[order[3]] and order[3] < order[1]):
        (order[1], order[3]) = (order[3], order[1])
    if current[order[1]] < current[order[2]] or (current[order[1]] == current[order[2]] and order[2] < order[1]):
        (order[1], order[2]) = (order[2], order[1])

    print(BASES[order[0]:order[0] + 1], end='')
    print(BASES[order[1]:order[1] + 1], end='')
    print(BASES[order[2]:order[2] + 1], end='')
    print(BASES[order[3]:order[3] + 1])
