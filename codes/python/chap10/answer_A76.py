import bisect

# 入力
N, W, L, R = map(int, input().split())
X = list(map(int, input().split()))

# 西岸を足場 0、東岸を足場 N+1 とみなす
X = [ 0 ] + X + [ W ]

# 動的計画法（書籍内の sum[i] は本コードの dpsum[i] に対応）
MOD = 10 ** 9 + 7 # = 1000000007
dp = [ 0 ] * (N + 2)
dpsum = [ 0 ] * (N + 2)
dp[0] = 1
dpsum[0] = 1
for i in range(1, N + 2):
	posl = bisect.bisect_left(X, X[i] - R)
	posr = bisect.bisect_left(X, X[i] - L + 1) - 1
	# dp[i] の値を累積和で計算（C++ とは異なり、（負の値）% MOD も 0 以上 MOD-1 以下になることに注意）
	dp[i] = (dpsum[posr] if posr >= 0 else 0) - (dpsum[posl - 1] if posl >= 1 else 0)
	dp[i] %= MOD
	# 累積和 dpsum[i] の値を更新
	dpsum[i] = dpsum[i - 1] + dp[i]
	dpsum[i] %= MOD

# 出力
print(dp[N + 1])