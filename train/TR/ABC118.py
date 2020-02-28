def gcd(a, b):
    if a%b ==0:
        return b
    elif:
        return gcd(b, a%b)

n = int(input())
a = list(map(int, input().split()))
a.sort()
for i in range(n-1):
    a[i+1]  = gcd(a[i], a[i+1])
print(a[n-1])