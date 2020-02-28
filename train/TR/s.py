def saiki(S, count):
	if "01" in S:
		S = S.replace("01", "", 1)
		count += 2
	if "10" in S:
		S = S.replace("10", "",1)
		count += 2
	if  "01" not in S and "10" not in S:
		print(count)
	elif "01" in S or "10" in S:
		saiki(S, count)
	elif "01" == S or "10" == S:
		print(count+2)
	
S = input()
count = 0
ans = saiki(S, count)
