x = str(input())
m = int(input())
l = int(max(str(x))) + 1
cp = l
r = 1e18 + 100

if len(x) == 1:
    if int(x) <= m:
        print(1)
    else:
        print(0)
    exit()


k = 0
for i, xx in enumerate(x[::-1]):
    k += int(xx) * (l ** i)
if  k > int(m):
    print(0)
    exit()

while r - l >= 2:
    mid = int((l + r) // 2)
    if mid == l:
        break
    k = 0
    #print(r, l)
    for i, xx in enumerate(x[::-1]):
        k += int(xx) * (mid ** i)
    #print(k)
    if int(k) <= int(m):
        l = mid
    else:
        r = mid

mid = r
k = 0
#print(r, l)
for i, xx in enumerate(x[::-1]):
    k += int(xx) * (mid ** i)
#print(k)
if int(k) <= int(m):
    print(r - cp + 1)
else:
    print(l - cp + 1)
