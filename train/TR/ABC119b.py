N = int(input())
jpy = 0
bit = 0
for i in range(N):
	x, y = input().split()
	if y == "JPY":
		jpy = jpy + float(x)
	else:
		bit = bit + float(x)
ans = jpy + bit*380000
print(ans)