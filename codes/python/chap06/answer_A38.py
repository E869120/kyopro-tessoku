# 入力
D, N = map(int, input().split())
L = [ None ] * N
R = [ None ] * N
H = [ None ] * N
for i in range(N):
	L[i], R[i], H[i] = map(int, input().split())

# 配列の初期化（1 日は 24 時間）
LIM = [ 24 ] * (D + 1)

# 上限値を求める
for i in range(N):
	for j in range(L[i], R[i]+1):
		LIM[j] = min(LIM[j], H[i])

# 答えを出力
Answer = 0
for i in range(1, D+1):
	Answer += LIM[i]
print(Answer)
