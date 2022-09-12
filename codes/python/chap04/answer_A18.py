# 入力
N, S = map(int, input().split())
A = list(map(int, input().split()))

# 動的計画法（i=0）
dp = [ [ None ] * (S + 1) for i in range(N + 1) ]
dp[0][0] = True
for i in range(1, S+1):
	dp[0][i] = False

# 動的計画法（i=1）
for i in range(1, N+1):
	for j in range(0,S+1):
		if j < A[i-1]:
			if dp[i-1][j] == True:
				dp[i][j] = True
			else:
				dp[i][j] = False

		if j >= A[i-1]:
			if dp[i-1][j] == True or dp[i-1][j-A[i-1]] == True:
				dp[i][j] = True
			else:
				dp[i][j] = False

# 出力
if dp[N][S] == True:
	print("Yes")
else:
	print("No")
