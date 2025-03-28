# BEGIN import factorisation.py
# Factorisation class
import subprocess
from collections import OrderedDict
class Factors:
    """ Class for factorisation of a number and getting divisors
    """
    factors = OrderedDict()
    def __init__(self, N):
        """ Initialises class with "factors" and their number in "factors" (OrderedDict)
        """
        results = subprocess.check_output(["factor", f"{N}"]).rstrip().split()
        results = list(map(int,results[1:]))
        for r in results:
            if r in self.factors:
                self.factors[r] += 1
            else:
                self.factors[r] = 1

    @staticmethod
    def __div(lst, result, I=0, prod=1):
        if I == len(lst):
            result.append(prod)
            return
        for i in range(lst[I][1]+1):
            Factors.__div(lst, result, I+1, prod)
            prod*=lst[I][0]


    def get_divisors(self):
        """ Returns sorted divisors of number it  was initiated with

        Complexity:
            O(sqrt(N)*log(N)) -- but this is really an upper bound, most likely much lesser.
        """
        l = [(a,b) for a, b in self.factors.items()]
        result = []
        Factors.__div(l, result)
        result.sort()
        return result

# END of import factorisation.py
#from __future__ import annotations
import sys
sys.setrecursionlimit(1000000)
def D(a):print(a)
def line():return sys.stdin.readline().strip()
def next_int():return int(line())
def line_ints():return list(map(int,line().split(" ")))

D(" ".join([str(i) for i in Factors(next_int()).factors]))
