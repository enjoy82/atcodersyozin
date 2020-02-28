W, a, b = map(int, input().split())
ans = 0
if a > b:
	a,b = b,a
if a+W >= b:
	print(ans)
else:
	ans = b-W-a
	print(ans)