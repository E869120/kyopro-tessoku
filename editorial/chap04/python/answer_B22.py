# 入力（A, B が 0 番目から始まっていることに注意）
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 配列 dp の初期化
dp = [ 2000000000 ] * N
dp[0] = 0

# 動的計画法
for i in range(N):
	if i <= N-2:
		dp[i+1] = min(dp[i+1], dp[i] + A[i])
	if i <= N-3:
		dp[i+2] = min(dp[i+2], dp[i] + B[i])

# 出力
print(dp[N-1])
