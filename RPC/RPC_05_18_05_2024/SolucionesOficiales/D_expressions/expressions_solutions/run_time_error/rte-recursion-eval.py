n,m = input().split(" ")
n=int(n)
m=int(m)
tokens = input().split(" ")
nums=[]
ops=[]

flag=True

for tk in tokens:
	if flag:
		nums += [tk]
	else:
		ops += [tk]
	flag = not flag

def ev(nums, ops):
	s=""
	s+=nums[0]
	for i in range(1,len(nums)):
		s+=ops[i-1] + nums[i]
	res = eval(s)
	if res % 2 == 0:
		print("even")
	else:
		print("odd")

ev(nums,ops)

for _ in range(m):
	x, y = input().split(' ')
	x=int(x)
	x -= 1
	nums[x] = y
	ev(nums,ops)

