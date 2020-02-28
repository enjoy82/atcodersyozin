def saiki(S, count):
	if "01" in S:
		S = S.replace("01", "", 1)
		count += 2
		print(S)
	if "10" in S:
		S = S.replace("10", "",1)
		count += 2
		print(S)
	if "01" == S or "10" == S:
		return count+2
	elif "01" in S or "10" in S:
		saiki(S, count)
	elif "01" not in S and "10" not in S:
		return count
	
S = input()
count = 0
print(saiki(S, count))
ans = saiki(S, count)
print(ans)

