

n = int(input())
for i in range(n):
	a = int(input())
	ans_list = []
	node = []
	for l in range(a):
		List = list(map(int, input().split()))
		node.append(List)
	path(0, 0, 0)
	print(max(ans_list))
