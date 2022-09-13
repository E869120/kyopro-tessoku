# 入力
N = int(input())
problems = [ list(map(int, input().split())) for i in range(N) ] # タプル (T[i], D[i]) が N 個並んだ配列になる

# D[i] の小さい順に並べ替える
problems.sort(key = lambda p: p[1])

# 動的計画法：前準備
MAX_D = max(map(lambda p: p[1], problems)) # D[i] の最大値（書籍内のコードでは「1440」という定数を使っているが、ここでは代わりに MAX_D を使うことにする）
dp = [ [ -(10 ** 10) ] * (MAX_D + 1) for i in range(N + 1) ]

# 動的計画法
dp[0][0] = 0
for i in range(N):
	t, d = problems[i] # 書籍中の T[i], D[i] に対応
	for j in range(MAX_D + 1):
		if j > d or j < t:
			dp[i + 1][j] = dp[i][j]
		else:
			dp[i + 1][j] = max(dp[i][j], dp[i][j - t] + 1)

# 答えを出力
answer = max(dp[N])
print(answer)