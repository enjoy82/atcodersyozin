a, b, c, d = map(int, input().split())
if a+b+c+d == 21 and a*b*c*d == 252:
	print("YES")
else:
	print("NO")