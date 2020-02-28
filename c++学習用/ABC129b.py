n = int(input())
w = list(map(int, input().split()))
ans = 1000000
w.sort
for i in w:
    b = w.index(i)
    c = sum(w[0:b+1])
    d = sum(w[b+1:n])
    if ans > abs(d-c):
        ans = abs(d-c)
print(ans)
