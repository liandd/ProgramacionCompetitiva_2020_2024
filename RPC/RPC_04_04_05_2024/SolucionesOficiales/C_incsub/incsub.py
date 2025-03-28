# Jacob Steinebronn
# incsub.py

n = int(input())
arr = list(map(int, input().split()))
res = 0

for i in range(n):
	j = i + 1
	while j < n and arr[j] > arr[j - 1]: 
		j += 1
	res = max(res, j - i)
print(res)	
