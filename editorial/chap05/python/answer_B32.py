# 入力
N, K = map(int, input().split())
A = list(map(int, input().split()))

# 勝者を計算する
# 配列 dp について： dp[x]=true のとき勝ちの状態、dp[x]=false のとき負けの状態
dp = [ None ] * (N + 1)
for i in range(N+1):
	dp[i] = False
	for j in range(K):
		if i>=A[j] and dp[i-A[j]]==False:
			dp[i] = True # 負けの状態に遷移できれば、勝ちの状態

# 出力
if dp[N] == True:
	print("First")
else:
	print("Second")
