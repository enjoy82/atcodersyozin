a, b = map(str, input().split("."))
a = int(a)
if (int(b[0]) % 10) >= 5:
    print(a+1)
else:
    print(a)