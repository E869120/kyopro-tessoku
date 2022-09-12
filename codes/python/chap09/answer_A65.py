# 入力（A[2], ..., A[N] が入力される値になるようにする）
N = int(input())
A = [ 0 ] * 2 + list(map(int, input().split()))

# 隣接リストの作成
G = [ list() for i in range(N + 1) ]
for i in range(2, N + 1):
	G[A[i]].append(i) # 上司 → 部下の方向に方向に辺を追加

# 動的計画法（dp[x] は社員 x の部下の数）
dp = [ 0 ] * (N + 1)
for i in range(N, 0, -1):
	for j in G[i]:
		dp[i] += (dp[j] + 1)

# 答え (dp[1], dp[2], ..., dp[N]) を空白区切りで出力
print(*dp[1:])