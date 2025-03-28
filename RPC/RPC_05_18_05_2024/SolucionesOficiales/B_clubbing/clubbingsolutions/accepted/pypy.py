#from __future__ import annotations
import sys
sys.setrecursionlimit(1000000)
def D(a):print(a)
def line():return sys.stdin.readline().strip()
def next_int():return int(line())
def line_ints():return list(map(int,line().split(" ")))
UU = 17
MX = 1<<UU
B = [0]*MX
T = 0
def toby(s):
    H = 0
    for c in s:
        H |= 1<<(ord(c)-97)
    return H

N = next_int()
for _ in range(N):
    B[toby(line())] = 1

for h in range(MX):
    for i in range(UU):
        B[h|(1<<i)] |= B[h]

S = line()
X = [[len(S) for _ in range(len(S)+1)] for _ in range(UU)]
for i in range(len(S)-1,-1,-1):
    for j in range(UU):
        X[j][i] = X[j][i+1]
    X[ord(S[i])-97][i] = i

for i in range(len(S)):
    H = 0
    I = i
    while True:
        if B[H]:
            T += len(S) - I
            break
        if I == len(S):
            break
        a, b = len(S) + 6, 0
        for j in range(UU):
            if not (H & (1<<j)) and X[j][I] < a:
                a, b = X[j][I], j
        H |= 1<<b
        I = a

D(T)
