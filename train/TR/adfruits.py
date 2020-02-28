def f(h, w):
    global ans, dp, a, b
    if  h == 0 and w == 0:
        return
    elif w == 0:
        ans = a[h-1] + ans
        f(h-1, w)
    elif h == 0:
        ans = b[w-1] + ans
        f(h, w-1)
    elif dp[h-1][w] == dp[h][w-1] == dp[h-1][w-1]:
        if (dp[h-1][w-1] == dp[h][w]-1):
            ans = a[h-1] + ans
            f(h-1, w-1)
        else:
            ans = a[h-1] + ans
            f(h-1, w)
    elif dp[h-1][w] != dp[h][w-1]:
        if dp[h][w] == dp[h][w-1]:
            ans = b[w-1] + ans
            f(h, w-1)
        elif dp[h][w] == dp[h-1][w]:
            ans = a[h-1] + ans
            f(h-1, w)

while True:
    try:
        a, b = input().split()
    except:
        break
    dp = [[0 for c in range(len(b)+1)] for c in range(len(a)+1)]
    for i in range(len(a)):
        for l in range(len(b)):
            sub = 0
            if a[i] == b[l]:
                sub = 1
            dp[i+1][l+1] = max(dp[i][l]+sub, dp[i][l+1], dp[i+1][l])
    ans = ""
    f(len(a), len(b))
    print(ans)