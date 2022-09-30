# 入力
N = int(input())
S = input()

# 動的計画法（初期状態）
dp = [ [ None ] * N for i in range(N) ]
for i in range(N):
	dp[i][i] = 1
for i in range(N-1):
	if S[i] == S[i+1]:
		dp[i][i+1] = 2
	else:
		dp[i][i+1] = 1

# 動的計画法（状態遷移）
for LEN in range(2,N):
	for l in range(N-LEN):
		r = l + LEN
		if S[l] == S[r]:
			dp[l][r] = max(dp[l][r-1], dp[l+1][r], dp[l+1][r-1]+2)
		else:
			dp[l][r] = max(dp[l][r-1], dp[l+1][r])

# 出力
print(dp[0][N-1])
