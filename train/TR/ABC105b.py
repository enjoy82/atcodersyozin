N = int(input())
ans = 0
for i in range(int(N/4)+1):
	for l in range(int(N/7)+1):
		if N == 4*i+7*l:
			ans = 1
if ans == 1:
	print("Yes")
else:
	print("No")