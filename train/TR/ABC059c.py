n = int(input())
N = list(map(int, input().split()))

# plus
ans1 = 0
subtotal = 0
for i in range(n):
	subtotal += N[i]
	if i % 2 == 0 and subtotal <= 0:
		diff = abs(subtotal) + 1
		subtotal += diff
		ans1 += diff
	elif i % 2 != 0 and subtotal >= 0:
		diff = abs(subtotal) + 1
		subtotal -= diff
		ans1 += diff

#minus
ans2 = 0
subtotal = 0
for i in range(n):
	subtotal += N[i]
	if i % 2 != 0 and subtotal <= 0:
		diff = abs(subtotal) + 1
		subtotal += diff
		ans2 += diff
	elif i % 2 == 0 and subtotal >= 0:
		diff = abs(subtotal) + 1
		subtotal -= diff
		ans2 += diff

print(min(ans1, ans2))