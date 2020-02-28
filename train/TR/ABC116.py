N = int(input())
a = list(map(int,input().split()))
c = 0
for i in range(N):
	if i == N-1:
		c = c + a[i]
		break
	if a[i] > a[i+1]:
		c = c + a[i]-a[i+1]
print(c)