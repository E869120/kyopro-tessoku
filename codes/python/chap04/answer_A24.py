import bisect

# 入力（A は 0 番目から始まることに注意！）
N = int(input())
A = list(map(int, input().split()))

# 動的計画法の準備
LEN = 0 # LEN は L の長さ（例：L[3] まで書き込まれている場合 LEN=4）
L = []  # 0 番目から始まることに注意
dp = [ None ] * N # 0 番目から始まることに注意

# 動的計画法（配列 dp を使った実装）
for i in range(N):
	pos = bisect.bisect_left(L, A[i])
	dp[i] = pos

	# 配列 L を更新
	if dp[i] >= LEN:
		L.append(A[i])
		LEN += 1
	else:
		L[dp[i]] = A[i]

# 答えを出力
print(LEN)
