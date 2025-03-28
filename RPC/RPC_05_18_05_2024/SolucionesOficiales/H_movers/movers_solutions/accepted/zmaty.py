THR = 300

n, m, q = tuple(int(i) for i in input().split())
in_d = [int(i) for i in input().split()]
in_g = [int(i) for i in input().split()]

cnt = [0 for i in range(n)]

g = {i: [] for i in range(n)}
for i in range(m):
    a, b = tuple(int(i) for i in input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

high_deg_g = {i: [j for j in g[i] if len(g[j]) >= THR] for i in range(n)}
ov = {i: 0 for i in range(n)}

def add(v, k):
    if len(g[v]) < THR:
        for j in g[v]:
            ov[j] += k
    cnt[v] += k

def get(v):
    return cnt[v] + ov[v] + sum(cnt[i] for i in high_deg_g[v])

for i in range(n):
    add(i, in_d[i] - in_g[i])

def ans(n):
    if n < 0:
        print("monitors")
    elif n == 0:
        print("same")
    else:
        print("desks")

for i in range(q):
    line = input().split()
    if line[0] == "check":
        ans(get(int(line[1]) - 1))
    else:
        k = int(line[1])
        k *= 1 if line[2] == "desk" else -1
        s = int(line[3]) - 1
        add(s, k)
