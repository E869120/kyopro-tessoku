# 入力
N, K = map(int, input().split())

# 出力
if K >= 2*N-2 and K%2 == 0:
	print("Yes")
else:
	print("No")
