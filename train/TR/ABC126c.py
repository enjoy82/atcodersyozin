N, K = map(int, input().split())
ans = 0
for i in range(1, N+1):
    a = i
    c = 0
    while a < K:
        a = a * 2
        c = c + 1
    ans = ans + (1/2)**c/N
print(ans)