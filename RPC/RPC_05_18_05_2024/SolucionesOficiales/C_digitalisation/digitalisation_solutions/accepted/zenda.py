N,M,C = [int(c) for c in input().split(' ')]
unies = [0 for i in range(M + 1)]
B = 0
R = 0

for i in range(N):
    a, b = [int(c) for c in input().split(' ')]
    if unies[a] < C:
        B += 1
        unies[a] +=1
    elif unies[b] < C:
        R += 1
        unies[b] +=1

print(B, R)