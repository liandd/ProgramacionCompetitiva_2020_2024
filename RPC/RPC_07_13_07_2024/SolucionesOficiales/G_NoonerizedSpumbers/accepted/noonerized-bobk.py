#!/usr/bin/python3

import sys

# get input equation
(x,op,y,eq,z) = input().split(' ')

# generate list of all proper prefix/suffix pairs for x
xList = []
for i in range(1,len(x)):
    xList.append([x[:i],x[i:]])

# same for y
yList = []
for i in range(1,len(y)):
    yList.append([y[:i],y[i:]])

# same for z
zList = []
for i in range(1,len(z)):
    zList.append([z[:i],z[i:]])

# try swapping all pairs of x and z prefixes
yPrime = int(y)
for xPair in xList:
    for zPair in zList:
        # swap parts and convert to integer
        xPrime = zPair[0] + xPair[1]
        xPrime = int(xPrime)

        zPrime = xPair[0] + zPair[1]
        zPrime = int(zPrime)

        # see if the equation is now correct
        if op == '+' and xPrime + yPrime == zPrime:
            print(xPrime,'+',yPrime,'=',zPrime)
            sys.exit(0)

        if op == '*' and xPrime * yPrime == zPrime:
            print(xPrime,'*',yPrime,'=',zPrime)
            sys.exit(0)

# same thing, now trying all y and z prefixes
xPrime = int(x)
for yPair in yList:
    for zPair in zList:
        yPrime = zPair[0] + yPair[1]
        yPrime = int(yPrime)

        zPrime = yPair[0] + zPair[1]
        zPrime = int(zPrime)

        if op == '+' and xPrime + yPrime == zPrime:
            print(xPrime, '+', yPrime, '=', zPrime)
            sys.exit(0)

        if op == '*' and xPrime * yPrime == zPrime:
            print(xPrime, '*', yPrime, '=', zPrime)
            sys.exit(0)

# same thing, now trying all x and y prefixes
zPrime = int(z)
for yPair in yList:
    for xPair in xList:
        yPrime = xPair[0] + yPair[1]
        yPrime = int(yPrime)

        xPrime = yPair[0] + xPair[1]
        xPrime = int(xPrime)

        if op == '+' and xPrime + yPrime == zPrime:
            print(xPrime, '+', yPrime, '=', zPrime)
            sys.exit(0)

        if op == '*' and xPrime * yPrime == zPrime:
            print(xPrime, '*', yPrime, '=', zPrime)
            sys.exit(0)

print('impossible')
