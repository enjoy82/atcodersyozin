import sys
H, W = map(int, input().split())
a = [[str(c) for c in l.strip()] for l in sys.stdin]
ans = "No"

def check(x, y):
	if(x<0 or x >= H or y<0 or y>=W):
		return
	else:
		search(x, y)
def search(x,y):
	if(a[x][y] == "#" or a[x][y] == "1"):
		return
	elif(a[x][y] == "g"):
		global ans
		ans = "Yes"
	a[x][y] = "1"
	check(x+1, y)
	check(x-1, y)
	check(x, y+1)
	check(x, y-1)

for i in range(H):
	for l in range(W):
		if(a[i][l] == "s"):
			check(i, l)
print(ans)