#from __future__ import annotations
import sys
sys.setrecursionlimit(1000000)
def D(a):print(a)
def line():return sys.stdin.readline().strip()
def next_int():return int(line())
def line_ints():return list(map(int,line().split(" ")))
X = Y = 0
N, M, C = line_ints()
A = [0] * (M + 1)
for _ in range(N):
    a, b = line_ints()
    if A[a] < C:
        A[a] += 1
        X += 1
    elif A[b] < C:
        A[b] += 1
        Y += 1

print(f"{X} {Y}")
