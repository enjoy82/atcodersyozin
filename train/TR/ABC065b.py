N = int(input())
a_list = [int(input()) for i in range(N)]
a = 0
c = 0
ans = -1
for l in range(N):
	c = c + 1
	a = a_list[a] - 1
	if a == 1:
		ans = c
		break
print(ans)