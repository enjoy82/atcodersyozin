N, M = map(int,input().split())
list1 = [0]*M
ans = 0
for i in range(N):
	a = list(map(int, input().split()))
	a.pop(0)
	for n in a:
		list1[n-1] = list1[n-1] + 1
for m in range(M):
	if list1[m] == N:
		ans = ans + 1
print(ans)