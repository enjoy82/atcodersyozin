def Gcd(a,b):
	if a<b:
		return Gcd(b,a)
	else:
		if a%b:
			return Gcd(b, a%b):
		else:
			return b
N = int(input())
arr = list(map(int,input().split()))
gcd = arr[0]
for i in arr:
	gcd = Gcd(gcd, i)
print(gcd)