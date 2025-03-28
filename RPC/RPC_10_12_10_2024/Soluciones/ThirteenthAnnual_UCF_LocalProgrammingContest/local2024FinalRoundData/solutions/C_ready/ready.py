
n,m = map(int, input().split())



seen = [0]*n
for _ in range(m):
    a,b = map(int, input().split())
    a-=1
    b-=1
    seen[a] |= (1<<b)

res = []
ans = 0
for a in seen:
    ans += 1
    if (a&3) == 3:
        res.append(ans)
print("\n".join(str(x) for x in res))
