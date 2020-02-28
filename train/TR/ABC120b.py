A, B, K = map(int,input().split())
b = []
for i in range(1, min(A,B)+1):
	if A%i == 0 and B%i == 0:
		b.append(i)
ans = b[-K]
print(ans)