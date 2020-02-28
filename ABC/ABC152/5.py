import fractions
import math
n = input()
li = list(map(int, input().split()))
a = 1
for i in li:
    a = a * i / fractions.gcd(a, i)
ans = 0
mod = 1000000007
for i in li:
    ans += (a / i) % mod
print(math.floor(ans))