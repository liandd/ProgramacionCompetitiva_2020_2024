
n,k = map(int, input().split())

better = 1+(2**(n))-k
ans = 0
while better:
    better //= 2
    ans += 1
ans = min(ans, n)
print(ans)
