# 入力
N, X = map(int, input().split())
A = list(map(int, input().split()))
Answer = False

# 全探索（変数 Answer は「既に x が見つかったかどうか」を表す）
for i in range(N):
	if A[i] == X:
		Answer = True

# 出力
if Answer == True:
	print("Yes")
else:
	print("No")
