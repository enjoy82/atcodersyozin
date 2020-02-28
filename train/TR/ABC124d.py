N, K = map(int,input().split())
s = input()
a = [int(c) for c in s]

b = []
c = 0
d = 0
for i in a:
	if(i == 1):
		if(d>0):
			b.append(d)
			d = 0
		c = c + 1
	else:
		if(c>0):
			b.append(c)
			c = 0
		d = d + 1
b.append(max(c,d))

ans = 0
e = 0
k = 2*K+1
if(a[0] == 1):
	for l in range(0,len(b), 2):
		e  = sum(b[l:l+2*K+1])
		if(ans < e):
			ans = e
else:
	for l in range(1,len(b), 2):
		e = sum(b[l:l+2*K+1])
		if(ans < e):
			ans = e
	if(sum(b[0:2*K]) > ans):
		ans = sum(b[0:2*K])
if(2*K > len(b)):
	ans = sum(b)
print(ans)