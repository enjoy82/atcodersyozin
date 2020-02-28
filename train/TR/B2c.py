xa, ya, xb, yb, xc, yc = map(int, input().split())
a = xb-xa
b = yb-ya
c = xc-xa
d = yc-ya
S = (a*d - b*c)/2
if S < 0:
	print(-1*S)
else:
	print(S)