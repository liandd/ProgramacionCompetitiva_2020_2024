

s1,x1,y1 = map(int, input().split())
s2,x2,y2 = map(int, input().split())

# Make the strong magnet centered at 0,0
x1 -= x2
y1 -= y2

# The area covered is only a function of the distance of the magnet and the ratio of the magnet strengths
# Rotate the point x1,y1 to a point that is on the x axis that is distance d from the origin (strong magnet)
# denote the distance as D
# denote as a point of equallibrium as x,y
# s1/dist1() = s2/dist2()
# s1(dist2()) = s2(dist1())
# s1(x*x + y*y) = s2((D-x)*(D-x) + (y)*(y))
# 0 = s2(D*D) - s2(2*D*x) + (s2-s1)(x*x) + (s2-s1)(y*y)
# let K be s2*D/(s2-s1)
# 0 = s2(D*D) - (s2-s1)(K*K) + (s2-s1)(K*K) - 2(s2-s1)[K]x + (s2-s1)(x*x) + (s2-s1)(y*y)
# 0 = [s2(D*D)-(s2-s1)(K*K)] + (s2-s1)((K-x)*(K-x) + y*y)
# [(s2-s1)(K*K)-s2(D*D)]/(s2-s1) = (K-x)^2 + y^2
# ^^^   is radius squared    ^^^
# answer is pi radius squared
D2 = (x1*x1+y1*y1)
# K = s2*D/(s2-s1)

# After some substitution and simplification we get the following...
# Answer = (3.1415926535897932384626433832795024)*((s2*s2)*(D2)/(s2-s1) - s2*(D2))/(s2-s1)
#Answer = (3.1415926535897932384626433832795024)*s2*D2((s2) - (s2-s1))/((s2-s1) * (s2-s1))
Answer = (3.1415926535897932384626433832795024)*s2*D2*s1/((s2-s1)*(s2-s1))

# I hate my life...
print(Answer)
