
# Problem: Easy Problem
# Author:  Coach Travis

# Read in the 4 values representing the number of solves by the i-th hour
h2,h4 = map(int, input().split())

# Check that the the number of people by the halfway mark is at least half 
# the contestants
if h2 * 2 >= h4:
    # Print that the problem is easy
    print("E")
else:
    # Print that the problem is hard
    print("H")
