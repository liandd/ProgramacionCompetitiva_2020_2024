
st = list((ord(x) - ord('a')) for x in input())
m,n = int(input()), len(st)

ans = 0
bptrs = [0]*26
skips = [0]*26
for i in range(n):
   x = st[i]
   for j in range(26): 
      if j != x:
         skips[j]+=1
         while skips[j] > m:
            if st[bptrs[j]] != j:
               skips[j] -= 1
            bptrs[j] += 1
   ans = max(ans, i+1-skips[x]-bptrs[x])
print(ans)

