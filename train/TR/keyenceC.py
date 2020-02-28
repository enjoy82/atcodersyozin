N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = sorted(A)
D = sorted(B)
e = 0
f = 0
for i in range(len(A)):
	C[i] >= D[i]
	e = e + 1
if e == len(A):
	for i in range(len(A)):
		if A[i] != C[i]:
			f = f + 1
	print(f)
else:
	print("-1")