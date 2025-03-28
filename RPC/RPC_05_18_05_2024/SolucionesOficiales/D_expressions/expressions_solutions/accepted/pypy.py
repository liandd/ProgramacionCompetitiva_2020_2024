#from __future__ import annotations
import sys
sys.setrecursionlimit(1000000)
def D(a):print(a)
def line():return sys.stdin.readline().strip()
def next_int():return int(line())
def line_ints():return list(map(int,line().split(" ")))
N, Q = line_ints()
x = line().split(" ")
P = [[0] * N for _ in range(2)]
I = [0] * N
A = [0] * N
l = T = 0
o = ["even", "odd"]
for i, c in enumerate(x):
    if i % 2:
        if c != "*":
            l = (i + 2) // 2
    else:
        P[int(c)%2][l] += 1
        I[i//2], A[i//2] = l, int(c)
for i in range(N):
    if P[1][i] and not P[0][i]:
        T += 1
print(o[T%2])
for _ in range(Q):
    a, b = line_ints()
    n = A[a-1]
    J = I[a-1]
    if P[1][J] and not P[0][J]:
        T -= 1
    P[n%2][J] -= 1
    A[a-1] = b
    P[b%2][J] += 1
    if P[1][J] and not P[0][J]:
        T += 1
    print(o[T%2])
