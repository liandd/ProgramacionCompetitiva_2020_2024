# Arup Guha
# 8/19/2024
# Alternate Solution to 2024 UCF Locals Problem: Christmas Tree Adapter

# Get input.
amp = int(input())
toks = input().split()
watt = int(toks[0])
volt = int(toks[1])

# What we're checking for.
if watt//volt >= amp:
    print(1)
else:
    print(0)
