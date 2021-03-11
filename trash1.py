import math
pi = math.pi
E = 1.0
C = 0.22*10**(-6)
R = 1000
f = [1, 10, 100, 300, 1000, 3000, 10000, 100000, 1000000]
for i in f:
    w = 2 * pi * i
    k = math.atan(2/(w*C*R)) * 180 / pi
    print(k)