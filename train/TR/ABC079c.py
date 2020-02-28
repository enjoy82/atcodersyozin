def calc(a, op, b):
	if op == "+":
		return a + b
	else:
		return a - b
s = input()
A, B, C, D = [int(c) for c in s]
ops = ["+", "-"]
ans = ""
for op1 in ops:
	for op2 in ops:
		for op3 in ops:
			if calc(calc(calc(A, op1, B), op2, C), op3, D) == 7:
				ans = str(A) + op1 + str(B) + op2 + str(C) + op3 + str(D) + "=7"

print(ans)
