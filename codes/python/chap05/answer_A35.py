# 入力
N = int(input())
A = list(map(int, input().split()))

# 配列 dp を定義
dp = [ [ None ] * (N+1) for i in range(N+1) ]

# 動的計画法 [N 段目]
for j in range(1, N+1):
	dp[N][j] = A[j-1]

# 動的計画法 [1 ～ N-1 段目]
for i in reversed(range(1, N)):
	for j in range(1, i+1):
		if i % 2 == 1:
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1])
		if i % 2 == 0:
			dp[i][j] = min(dp[i+1][j], dp[i+1][j+1])

# 出力
print(dp[1][1])
