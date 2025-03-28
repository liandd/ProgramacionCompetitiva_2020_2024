import bisect

G = 101
L = 5

n = int(input())

inp = []
for i in range(n):
    g, l, p = input().split()
    g = int(g)
    p = int(p)
    p = -p
    l = ord(l if l != 'F' else 'E') - ord('A')
    inp.append((g, l, p))

ps = sorted(set(t[2] for t in inp))
reqs = [[[] for _ in range(L)] for _ in range(G)]

for g, l, p in inp:
    p = bisect.bisect_left(ps, p)
    reqs[g][l].append(p)

def compare(a, b):
    assert(len(a) == len(b))
    for ai, bi in zip(a, b):
        if ai != bi:
            return ai < bi
    return False

dp = [[[0] * len(ps) for _ in range(L)] for _ in range(G)]
cutoff = [[False] * L for _ in range(G)]

for l in range(L-1):
    dp[0][l][0] = -(10**9)

for g in range(G):
    if g > 0:
        for l in range(L):
            cutoff[g][l] = l < L-1 and not compare(dp[g-1][l+1], dp[g-1][l])
            dp[g][l] = (dp[g-1][l+1] if cutoff[g][l] else dp[g-1][l]).copy()

    for l in range(L):
        for p in reqs[g][l]:
            dp[g][l][p] += 1

g = 100
out = []

for l in range(L - 1):
    while not cutoff[g][l]:
        g -= 1
    out.append(g)
    g -= 1

print(" ".join(str(x) for x in out))
