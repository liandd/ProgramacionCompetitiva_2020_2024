def get_denom(p):
    if p %2 == 0:
        return 2
    i = 3
    while i * i <= p:
        if p % i == 0:
            return i
        i += 2
    return None

n = int(input())
p = get_denom(n)
print(p, n//p)
