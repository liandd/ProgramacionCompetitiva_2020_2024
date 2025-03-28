#from __future__ import annotations
import sys
sys.setrecursionlimit(1000000)
def D(a):print(a)
def line():return sys.stdin.readline().strip()
def next_int():return int(line())
def line_ints():return list(map(int,line().split(" ")))
B, Q = line_ints()
s = f".{line()}."
X = format(B, "08b").replace("1", "X").replace("0", ".")
for _ in range(Q):
    r = "."
    for i in range(1, len(s) - 1):
        r += X[-int(s[i-1:i+2].replace("X", "1").replace(".", "0"), 2)-1]
    r += "."
    print(r[1:-1])
    s = r
