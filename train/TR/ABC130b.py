n, x =map(int, input().split())
l = list(map(int, input().split()))
ans = 1
d = 0
for i in l:
    d = d + i
    if d <= x:
        ans = ans + 1
print(ans)