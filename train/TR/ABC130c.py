w, h, x, y = map(int, input().split())
ans = w*h/2
if x == w/2 and y == h/2:
    print('{} 1'.format(ans))
else:
    print('{} 0'.format(ans))