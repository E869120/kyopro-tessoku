# 入力
N, X, Y = map(int, input().split())
A = list(map(int, input().split()))

# Grundy 数を計算
XOR_Sum = 0
for i in range(N):
	Grundy = [0, 0, 1, 1, 2] # 5 で割った余りに対応する Grundy 数
	XOR_Sum ^= Grundy[A[i] % 5]

# 出力
if XOR_Sum != 0:
	print("First")
else:
	print("Second")
