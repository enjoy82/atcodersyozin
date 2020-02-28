def path(count, ans, pos):
	if count == a:
		ans_list.append(ans)
	else:
		ans = ans + node[count][pos]
		if ans > Dl[count][pos]:
			Dl[count][pos] = ans
			path(count+1, ans, pos)
			path(count+1, ans, pos+1)
		else:
			pass

n = int(input())
for i in range(n):
	a = int(input())
	ans_list = []
	Dl = [[0 for m in range(a)] for n in range(a)]
	node = []
	for l in range(a):
		List = list(map(int, input().split()))
		node.append(List)
	path(0, 0, 0)
	print(max(ans_list))
