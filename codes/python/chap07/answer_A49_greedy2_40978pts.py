################################################
# 本の 272 ページ後半の評価関数を用いた実装です
################################################

# 入力
T = int(input())
P = [ None ] * T
Q = [ None ] * T
R = [ None ] * T
for i in range(T):
	P[i], Q[i], R[i] = map(int, input().split())
	P[i] -= 1 # 0 始まりに直す
	Q[i] -= 1
	R[i] -= 1

# 配列 A の初期化
A = [ 0 ] * 20

# 貪欲法
for i in range(T):
	# パターン A の場合のスコアを求める
	ScoreA = 0
	PatA = [ 0 ] * 20
	for j in range(20):
		PatA[j] = A[j]
	PatA[P[i]] += 1
	PatA[Q[i]] += 1
	PatA[R[i]] += 1
	for j in range(20):
		ScoreA += abs(PatA[j])

	# パターン B の場合のスコアを求める
	ScoreB = 0
	PatB = [ 0 ] * 20
	for j in range(20):
		PatB[j] = A[j]
	PatB[P[i]] -= 1
	PatB[Q[i]] -= 1
	PatB[R[i]] -= 1
	for j in range(20):
		ScoreB += abs(PatB[j])

	# スコアの小さい方を採用
	if ScoreA <= ScoreB:
		print("A")
		CurrentScore = ScoreA
		for j in range(20):
			A[j] = PatA[j]
	else:
		print("B")
		CurrentScore = ScoreB
		for j in range(20):
			A[j] = PatB[j]
