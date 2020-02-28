A, B = map(int, input().split())
ans = 0
for i in range(A, B+1):
	ans = ans ^ i
print(ans)