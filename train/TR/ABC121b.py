N, M, C = map(int, input().split())
b_list = list(map(int,input().split()))
c = 0
for i in range(N):
	a_list = list(map(int, input().split()))
	sum = 0
	for i in range(M):
		sum = b_list[i] * a_list[i] + sum
	sum = sum + C
	if sum > 0:
		c = c + 1
print(c)