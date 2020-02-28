s = int(input())
n = s
c = 1
a = []
a.append(s)
for i in range(1000000):
	if n % 2 == 0:
		c = c + 1
		n = n /2
		if n in a:
			break
		a.append(n)
	else:
		c = c + 1
		n = 3*n + 1
		if n in a:
			break
		a.append(n)
print(c)