# 入力
N, Q = map(int, input().split())
A = list(map(int, input().split()))
queries = [ list(map(int, input().split())) for i in range(Q) ]

# 前計算（ここでは書籍とは異なり、0-indexed で実装しています）
LEVELS = 30
dp = [ [ None ] * N for i in range(LEVELS) ]
for i in range(0, N):
	dp[0][i] = A[i] - 1
for d in range(1, LEVELS):
	for i in range(0, N):
		dp[d][i] = dp[d - 1][dp[d - 1][i]]

# クエリの処理（ここでは書籍とは異なり、0-indexed で実装しています）
for X, Y in queries:
	current_place = X - 1
	for d in range(29, -1, -1):
		if ((Y >> d) & 1) == 1:
			current_place = dp[d][current_place]
	print(current_place + 1) # current_place は 0-indexed で計算したので、1 を足して出力する

# 注意 1：書籍の C++ プログラムにおいて「Y の 2^d の位を取り出す」は C++ では (Y / (1 << d)) % 2 と実装されていました。
#         Python でも 19 行目は (Y // (2 ** d)) % 2 と実装できますが、((Y >> d) & 1) と計算すると、定数倍の面でより高速です。
# 注意 2：このプログラムの平均的な実行時間は 2 秒にギリギリ入るくらいであり、提出によっては TLE となる場合があります。
#         同じプログラムを PyPy3 で提出すると、0.5 秒程度の実行時間で AC することができます。