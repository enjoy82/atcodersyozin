N = int(input())
v_list = list(map(int,input().split()))
c_list = list(map(int,input().split()))
ans = []
for i in range(N):
    if v_list[i] > c_list[i]:
        ans.append(v_list[i]-c_list[i])
print(sum(ans))