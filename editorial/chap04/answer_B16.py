# 入力
N = int(input())
H = list(map(int, input().split()))

# 配列の準備
dp = [ None ] * N

# 動的計画法
dp[0] = 0
dp[1] = abs(H[0] - H[1])
for i in range(2, N):
	dp[i] = min(dp[i-1] + abs(H[i-1]-H[i]), dp[i-2] + abs(H[i-2]-H[i]))

# 出力
print(dp[N-1])
