# 入力
N, A, B = map(int, input().split())

# 配列 dp を定義
# dp[x]=True のとき勝ちの状態、dp[x]=False のとき負けの状態
dp = [ None ] * (N+1)

# 勝者を計算する
for i in range(N+1):
	if i >= A and dp[i-A] == False:
		dp[i] = True
	elif i >= B and dp[i-B] == False:
		dp[i] = True
	else:
		dp[i] = False

# 出力
if dp[N] == True:
	print("First")
else:
	print("Second")
