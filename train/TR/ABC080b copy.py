A = int(input())
N = A
a = []
for i in reversed(range(len(str(N)))):
	a.append(int(N/10**(i)))
	N -= int(N/10**i)*10**i
X = sum(a))
if A % X == 0:
	print("Yes")
else:
	print("No")