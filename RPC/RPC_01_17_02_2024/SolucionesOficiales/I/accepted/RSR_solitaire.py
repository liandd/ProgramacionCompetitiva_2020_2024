#!/usr/bin/env python3

from collections import deque
import sys

cards = deque(sys.stdin.readline().split())
cards.extend(sys.stdin.readline().split())
cards.extend(sys.stdin.readline().split())
cards.extend(sys.stdin.readline().split())

def check(i):
  if i < 3 or i >= len(cards): return 0
  if cards[i][0] == cards[i-3][0]: return 4
  if cards[i][1] == cards[i-3][1]: return 2
  return 0

def display(cards):
  #for i in range(len(cards)):
  #  print(f'{i:2}',end=" ")
  #print()
  print(cards[0],end="")
  for i in range(1,len(cards)):
    print(' '+cards[i],end="")
  print()


i = base = 3
while i < len(cards):
  # check all cards from i down to base; find max change and process it
  maxd = 0
  maxi = -1
  for j in reversed(range(base,i+1)):
    c = check(j)
    if c > maxd:
      maxd = c
      maxi = j
  # Perform removal, if any, adjust i and base as needed
  if maxd == 4:
    #print(f'removing cards {maxi-3} through {maxi}')
    del cards[maxi]
    del cards[maxi-1]
    del cards[maxi-2]
    del cards[maxi-3]
    i = max(3,i-4)
    base = min(base,i)
    #display(cards)
  elif maxd == 2:
    #print(f'removing cards {maxi-3} and {maxi}')
    del cards[maxi]
    del cards[maxi-3]
    i = max(3,i-2)
    base = max(3,min(base,i-1)) 
    #display(cards)
  else:
    i += 1

print(len(cards),end="")
if len(cards) > 0:
  print(' ',end="")
  display(cards)
else:
  print()
