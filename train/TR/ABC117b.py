N = int(input())
a = list(map(int, input().split()))
b = max(a)
a.pop(a.index(max(a)))
c = sum(a)
if c > b:
	print("Yes")
else:
	print("No")