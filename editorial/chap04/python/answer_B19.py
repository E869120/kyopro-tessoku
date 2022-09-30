# 入力
N, W = map(int, input().split())
w = [ None ] * (N + 1)
v = [ None ] * (N + 1)
for i in range(1, N+1):
	w[i], v[i] = map(int, input().split())

# 動的計画法
dp = [ [ 10 ** 15 ] * 100001 for i in range(N + 1) ]
dp[0][0] = 0
for i in range(1, N+1):
	for j in range(100001):
		if j < v[i]:
			dp[i][j] = dp[i-1][j]
		if j >= v[i]:
			dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i])

# 出力
Answer = 0
for i in range(100001):
	if dp[N][i] <= W:
		Answer = i
print(Answer)
