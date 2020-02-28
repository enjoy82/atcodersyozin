N, M = map(int, input().split())
X = list(map(int, input().split()))
if N < M:
	x = sorted(X)
	B = []
	for i in range(0, M-1):
		B.append(x[i+1]-x[i])
	B.sort(reverse=True)
	for l in range(N-1):
		B.pop(0)
	print(sum(B))
else:
	print(0)