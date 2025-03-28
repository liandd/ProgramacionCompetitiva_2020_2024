
p1,q1,p2,q2 = map(int, input().split())

# Min cases
if not p1 or not q1 or not p2 or not q2:
   print(0)
   exit()

# Make fraction
q1 += p1
q2 += p2

# Make fraction 1 smaller than fraction 2
if p2 == 0 or (p1 != 0 and (p1 * q2 > p2 * q1)):
   p1,q1,p2,q2=p2,q2,p1,q1

q3 = 1
ans = 0


while 1:
   # Find numerator
   q3 *= 2
   p3 = (q3 * p2) // q2


   ans += 1
   if p3 * q1 >= p1 * q3 and p3 * q2 <= p2 * q3:
      break
print(ans)
