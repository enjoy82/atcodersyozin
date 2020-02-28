N, M = map(int, input().split())
ans = [-1, -1, -1]
if 4*N < M:
	print(ans[0],ans[1],ans[2])
else:
	for i in range(0, N+1):
		for l in range(0, N-i+1):
			if 2*i + 3*l+ 4*(N-i-l) == M:
				ans = [i, l, N-i-l]
	print(ans[0],ans[1],ans[2])