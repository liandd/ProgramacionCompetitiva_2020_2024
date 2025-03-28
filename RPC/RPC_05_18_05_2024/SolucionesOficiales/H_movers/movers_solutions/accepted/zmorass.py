#from __future__ import annotations
import sys
sys.setrecursionlimit(1000000)
def line():return sys.stdin.readline().strip()
def next_int():return int(line())
def line_ints():return list(map(int,line().split(" ")))
SQ = 1000
N, M, Q = line_ints()
D = line_ints()
G = line_ints()
g = [[] for _ in range(N)]
B = []
E = set()
X = [0] * N
Y = [0] * N
def bf(u):
    a, b = D[u], G[u]
    for v in g[u]:
        a += D[v]
        b += G[v]
    return a, b
for _ in range(M):
    a, b = line_ints()
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)
    E.add((a,b))
    E.add((b,a))
for i in range(N):
    if len(g[i]) >= SQ:
        B.append(i)
for i in range(N):
    X[i], Y[i] = bf(i)
def rs(x, y):
    if x == y:
        return "same"
    if x > y:
        return "desks"
    return "monitors"
for _ in range(Q):
    l = line()
    if l[0] == "c":
        u = int(l.split(" ")[1]) - 1
        if u in B:
            print(rs(X[u], Y[u]))
        else:
            print(rs(*bf(u)))
    else:
        _, n, w, u = l.split(" ")
        u = int(u) - 1
        n = int(n)
        if w == "desk":
            D[u] += n
        else:
            G[u] += n
        if u in B:
            if w == "desk":
                X[u] += n
            else:
                Y[u] += n
        for s in B:
            if (u, s) in E:
                if w == "desk":
                    X[s] += n
                else:
                    Y[s] += n
