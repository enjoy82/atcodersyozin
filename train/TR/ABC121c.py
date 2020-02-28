N, M = map(int, input().split())
dict = {}
for i in range(N):
	A, B = map(int, input().split())
	dict[A] = B
dict_sorted = sorted(dict.items())
sum = 0
ans = 0
for i in dict_sorted:
	k = i[0]
	v = i[1]
	ans = k * v + ans
	sum = sum + v
	if sum >= M:
		break
a = sum - M
ans = ans - a*k
print(ans)