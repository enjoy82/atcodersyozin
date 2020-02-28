def swit(count, ON_list):
    global ans
    if count == N:
        for l in range(M):
            d = 0
            for m in range(1,len(a[l])):
#                print(ON_list)
                if ON_list[a[l][m]-1] == 1:
                    d = d + 1
            if d % 2 != p[l]:
                return 0
        ans = ans + 1
    else:
        for l in range(2):
            ON_list[count] = l
            swit(count+1, ON_list)

N, M = map(int, input().split())
a = []
for i in range(M):
    b = list(map(int, input().split()))
    a.append(b)
p = list(map(int, input().split()))
ans = 0
swit(0, [0]*N)
print(ans)