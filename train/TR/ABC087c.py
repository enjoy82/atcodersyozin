N = int(input())
x_list = list(map(int, input().split()))
y_list = list(map(int, input().split()))
ans = 0
if N == 1:
	print(x_list[0] + y_list[0])
else:
	for i in range(N):
		a = sum(x_list[0:i+1]) + sum(y_list[i:N])
		if ans < a:
			ans = a
	print(ans)