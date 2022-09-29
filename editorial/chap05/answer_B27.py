def GCD(A, B):
	while A >= 1 and B >= 1:
		if A >= B:
			A = A % B # A の値を変更する場合
		else:
			B = B % A # B の値を変更する場合
	if A >= 1:
		return A
	return B

# 入力
A, B = map(int, input().split())
print(A * B // GCD(A, B))
