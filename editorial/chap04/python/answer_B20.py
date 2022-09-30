# 入力
S = input()
T = input()

# 配列の準備
dp = [ [ None ] * (len(T) + 1) for i in range(len(S) + 1) ]

# 動的計画法
dp[0][0] = 0
for i in range(len(S)+1):
	for j in range(len(T)+1):
		if i>=1 and j>=1 and S[i-1]==T[j-1]:
			dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1])
		elif i>=1 and j>=1:
			dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1)
		elif i>=1:
			dp[i][j] = dp[i-1][j]+1
		elif j>=1:
			dp[i][j] = dp[i][j-1]+1

# 出力
print(dp[len(S)][len(T)])
