# 入力（前半）
N = int(input())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 入力（後半）
Q = int(input())
A = [ None ] * Q
B = [ None ] * Q
C = [ None ] * Q
D = [ None ] * Q
for i in range(Q):
	A[i], B[i], C[i], D[i] = map(int, input().split())

# 各座標にある点の数を数える
S = [ [ 0 ] * 1501 for i in range(1501) ]
for i in range(N):
	S[X[i]][Y[i]] += 1

# 累積和をとる
T = [ [ 0 ] * 1501 for i in range(1501) ]
for i in range(1, 1501):
	for j in range(1, 1501):
		T[i][j] = T[i][j-1] + S[i][j]
for j in range(1, 1501):
	for i in range(1, 1501):
		T[i][j] = T[i-1][j] + T[i][j]

# 答えを求める
for i in range(Q):
	print(T[C[i]][D[i]] + T[A[i] - 1][B[i] - 1] - T[A[i] - 1][D[i]] - T[C[i]][B[i] - 1])
