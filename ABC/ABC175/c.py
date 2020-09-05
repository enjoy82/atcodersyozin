X, K, D = map(int, input().split())
mid = abs(X)
if K*D > mid:
    mm = mid // D
    K = K - mm
    mid = mid - mm * D
    if K % 2 == 0:
        print(mid)
    else:
        print(abs(mid - D))
else:
    print(mid - K * D)