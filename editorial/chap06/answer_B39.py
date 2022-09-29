# 入力
N, D = map(int, input().split())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 配列の準備
# used[i] は仕事 i を選んだかどうか
used = [ False ] * N

# 答えを求める
Answer = 0
for i in range(1, D+1):
	maxValue = 0 # 給料の最大値
	maxID = -1   # 給料が最大となる仕事の番号
	for j in range(N):
		if used[j] == False and maxValue < Y[j] and X[j] <= i:
			maxValue = Y[j]
			maxID = j

	# 選べる仕事がある場合
	if maxID != -1:
		Answer += maxValue
		used[maxID] = True

# 出力
print(Answer)
