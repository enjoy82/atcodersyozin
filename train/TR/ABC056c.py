X = int(input())
walk = ans = 0
while X > walk:
	ans = ans + 1
	walk = walk + ans
print(ans)