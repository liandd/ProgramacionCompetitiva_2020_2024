#!/usr/bin/python3
from sys import stdin

"""
Process the cards in order and follow the rules.

author: Finn Lidbetter
"""


def do_removals(flipped):
    if len(flipped) < 3:
        return flipped
    removed = True
    while removed:
        removed = False
        first_rank_match = None
        first_suit_match = None
        for i in range(len(flipped) - 1, 2, -1):
            if first_rank_match is None and flipped[i][0] == flipped[i-3][0]:
                first_rank_match = i
            if first_suit_match is None and flipped[i][1] == flipped[i-3][1]:
                first_suit_match = i
        if first_rank_match is not None:
            flipped = flipped[:first_rank_match - 3] + flipped[first_rank_match + 1:]
            removed = True
        elif first_suit_match is not None:
            flipped = flipped[:first_suit_match - 3] + flipped[first_suit_match - 2:first_suit_match] + flipped[first_suit_match + 1:]
            removed = True
    return flipped

def main():
    line = stdin.readline().strip()
    cards = []
    while line:
        cards.extend(line.split(' '))
        line = stdin.readline().strip()
    
    flipped = []
    for card in cards:
        flipped.append(card)
        flipped = do_removals(flipped)
    print(f"{len(flipped)} {' '.join(flipped)}")
    

if __name__ == '__main__':
    main()
