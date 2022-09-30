# 入力
N = int(input())

# 10 の N 乗を求める
Power10 = [ None ] * 17
for i in range(17):
	Power10[i] = 10 ** i

# R[i][j] の値を計算
R = [ [ None ] * 10 for i in range(17) ]
for i in range(16):
	# 下から i 桁目の数字を求める
	Digit = (N // Power10[i]) % 10;

	# R[i][j] の値を求める
	for j in range(10):
		if j < Digit:
			R[i][j] = (N // Power10[i + 1] + 1) * Power10[i]
		if j == Digit:
			R[i][j] = (N // Power10[i + 1]) * Power10[i] + (N % Power10[i]) + 1
		if j > Digit:
			R[i][j] = (N // Power10[i + 1]) * Power10[i]

# 答えを求める
Answer = 0
for i in range(16):
	for j in range(10):
		Answer += j * R[i][j]

# 出力
print(Answer)
