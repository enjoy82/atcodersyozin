A, B, Q = map(int, input().split())
s = [int(input()) for i in range(A+B)]
x = [int(input()) for i in range(Q)]
for a in range(Q):
	X = x[a]
	diff1 = 10000000000
	ind = 0
	for b in range(A+B):
		l = abs(X-s[b])
		if diff1 > l:
			ind = b
			diff1 = l
	ans = diff1
	X = s[ind]
	diff2 = 10000000000
	if ind >= A:
		for c in range(A):
			l = abs(X - s[c])
			if diff2 > l:
				diff2 = l
	else:
		for c in range(A, A+B):
			l = abs(X - s[c])
			if diff2 > l:
				diff2 = l
	ans = ans + diff2
	print(ans)