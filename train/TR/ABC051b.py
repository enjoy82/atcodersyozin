K, S = map(int, input().split())
count = 0
for i in range(K+1):
	for l in range(K+1):
		if S - i - l <= K and S - i - l >=0: 
			count = count + 1
print(count)