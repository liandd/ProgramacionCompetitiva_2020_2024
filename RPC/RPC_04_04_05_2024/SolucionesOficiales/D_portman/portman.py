# Jacob Steinebronn
# portman.py

a = input().strip()
b = input().strip()[::-1] # reversed
vows = "aeiou"

for i, c in enumerate(a):
	if i and c in vows: 
		break

for j, c in enumerate(b):
	if j and c in vows:
		break

# Variables don't go out of scope in python, so i, j, and c are valid
if c in vows:
	# If we didn't find a vowel in a, take the whole string
	if a[i] not in vows: i = len(a)
	print(a[:i] + b[:j+1][::-1])
elif a[i] in vows:
	print(a[:i+1] + b[::-1])
else: 
	print(a + 'o' + b[::-1])
