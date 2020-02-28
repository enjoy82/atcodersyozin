N, Y = map(int, input().split())
ans = "-1 -1 -1"
for a in range(N+1):
	for b in range(N+1-a):
		if  1000 * (N-(a+b)) + 5000*b + 10000*a == Y:
			ans = str(a)+ " " + str(b) + " " + str(N-a-b)
print(ans)