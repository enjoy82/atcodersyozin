N = int(input())
H = int(input())
W = int(input())
if H > N or W > N:
	print(0)
else:
	print((N-W+1)*(N-H+1))