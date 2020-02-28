N = int(input())
a = int(input())
for i in range(N-1):
	T = int(input())
	if T < a:
		a = T
print(a)