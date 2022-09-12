# 入力（A, B が 0 番目から始まっていることに注意）
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 動的計画法
dp = [ None ] * (N+1)
dp[1] = 0
dp[2] = A[0]
for i in range(3, N+1):
	dp[i] = min(dp[i-1]+A[i-2], dp[i-2]+B[i-3])

# 出力
print(dp[N])
