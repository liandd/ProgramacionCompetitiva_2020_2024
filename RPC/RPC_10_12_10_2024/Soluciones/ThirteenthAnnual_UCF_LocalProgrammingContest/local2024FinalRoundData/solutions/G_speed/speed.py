
n,L = map(int, input().split())

boosts = [list(int(x) for x in input().split()) for _ in range(n)]


boosts.sort()

timeToGet = [a[0] for a in boosts]

ans = L
for i in range(n):
   for j in range(i+1,n):
      if boosts[i][0] + boosts[i][2]*boosts[i][1] <= boosts[j][0]:
         timeToGet[j] = min(timeToGet[j], timeToGet[i] + boosts[i][2] + (boosts[j][0] - boosts[i][0] - boosts[i][1]*boosts[i][2]))
   if boosts[i][0] + boosts[i][2]* boosts[i][1] <= L:
      ans = min(ans, timeToGet[i] + (L - boosts[i][0] - boosts[i][1]*boosts[i][2]) + boosts[i][2])
   else:
      ans = min(ans, timeToGet[i] + (L - boosts[i][0]) / boosts[i][1])
print(ans)
