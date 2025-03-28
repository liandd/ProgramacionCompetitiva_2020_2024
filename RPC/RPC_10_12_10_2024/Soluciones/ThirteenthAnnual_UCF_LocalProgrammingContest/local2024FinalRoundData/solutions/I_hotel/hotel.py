
RESERVE = 'R'
COUNT = 'A'

n,q = map(int, input().split())

BIT = [0]*(n+1)
avail = [1] * (n+1)

for _ in range(q):
   line = list(x for x in input().split())
   if line[0] == RESERVE:
      index = int(line[1])
      if not avail[index]: continue
      avail[index] = 0
      while index < len(BIT):
         BIT[index] += 1
         index += index-(index&(index-1))
   else:
      st = int(line[1])-1
      en = int(line[2])
      ans = en - st
      while st:
         ans += BIT[st]
         st -= st-(st&(st-1))
      while en:
         ans -= BIT[en]
         en -= en-(en&(en-1))
      print(ans)



