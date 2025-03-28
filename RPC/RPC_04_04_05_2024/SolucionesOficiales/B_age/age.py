# Jacob Steinebronn
# 8/21/2023

o, a, k = list(map(int, input().split()))

# Brute-force it, since age is never > 150 we know neither coefficient is either
for i in range(1, 160):
	for j in range(1, 160):
		if (i*a + j*k) == o:
			print(1)
			exit(0)

print(0)
