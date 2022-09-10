# 入力
N = int(input())
T = [ None ] * N
A = [ None ] * N
for i in range(N):
	T[i], A[i] = input().split()
	A[i] = int(A[i])

# 出力（Answer は現在の黒板の数）
Answer = 0
for i in range(N):
	if T[i] == '+':
		Answer += A[i]
	if T[i] == '-':
		Answer -= A[i]
	if T[i] == '*':
		Answer *= A[i]

	# 引き算で答えが 0 未満になった場合
	if Answer < 0:
		Answer += 10000

	# ここで余りをとっている！
	Answer %= 10000
	print(Answer)
