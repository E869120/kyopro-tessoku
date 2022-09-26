dp = [[0] * 300009 for _ in range(30)]
 
# 入力
N, K = map(int, input().split())

# 1 回操作した後の値を求める
for i in range(N + 1):
	dp[0][i] = i - sum(map(int, str(i)))

# 前計算
for d in range(29):
	for i in range(N + 1):
		dp[d + 1][i] = dp[d][dp[d][i]]

# 答えを求める
for num in range(1, N + 1):
	for d in range(30):
		if K & (1 << d):
			num = dp[d][num]
	print(num)
