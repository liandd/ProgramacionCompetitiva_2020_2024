#!/usr/bin/python3


def dijkstra(ss):
    global data
    global selected
    global parent
    global adj

    data[ss] = 0

    for ii in range(len(data)):
        nn = -1
        for jj in range(len(data)):
            if (nn == -1 or data[jj] < data[nn]) and not selected[jj]:
                nn = jj
        selected[nn] = True

        for ee in adj[nn]:
            if data[nn] + ee[1] < data[ee[0]] and not selected[ee[0]]:
                parent[ee[0]] = nn
                data[ee[0]] = data[nn] + ee[1]


(n, m, a, b) = map(int, input().split(' '))
adj = []
for i in range(n):
    adj.append([])
for i in range(m):
    (i1, i2, ll) = map(int, input().split(' '))
    i1 -= 1
    i2 -= 1
    adj[i1].append([i2, ll])
    adj[i2].append([i1, ll])

a -= 1
b -= 1

data = [99999999] * n
selected = [False] * n
parent = [-1] * n

dijkstra(a)

bestA = data.copy()

for i in range(n):
    data[i] = 99999999
    selected[i] = False
    parent[i] = -1

dijkstra(b)

savings = 0
for i in range(n):
    for e in adj[i]:
        if e[0] > i and bestA[i] + e[1] + data[e[0]] != data[a] and data[i] + e[1] + bestA[e[0]] != data[a]:
            savings += e[1]

print(savings)
