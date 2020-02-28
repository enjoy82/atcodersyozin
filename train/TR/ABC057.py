def gcd(A, B, C, D):
	l, L = A-C, B-D
	if l<0:
		l = l*(-1)
	if L<0:
		L = L*(-1)
	return l+L
	
N, M = map(int, input().split())
x = []
y = []
n = 0
m = 0
ans = 1
for i in range(N):
	x1, y1 = map(int, input().split())
	x.append(x1)
	y.append(y1)
X = []
Y = []
for l in range(M):
	x2, y2 = map(int, input().split())
	X.append(x2)
	Y.append(y2)
for a in range(N):
	m = gcd(x[a], y[a], X[0], Y[0])
	for b in range(M):
		n = gcd(x[a], y[a], X[b], Y[b])
		if n < m:
			m = n
			ans = b+1
	print(ans)
	ans = 1