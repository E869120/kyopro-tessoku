# 入力
H, W, N = map(int, input().split())
A = [ None ] * N
B = [ None ] * N
C = [ None ] * N
D = [ None ] * N
X = [ None ] * (W)
for t in range(N):
	A[t], B[t], C[t], D[t] = map(int, input().split())

# 各日について加算
X = [ [ 0 ] * (W + 2) for i in range(H + 2) ]
Z = [ [ 0 ] * (W + 2) for i in range(H + 2) ]
for t in range(N):
    X[A[t]][B[t]] += 1
    X[A[t]][D[t]+1] -= 1
    X[C[t]+1][B[t]] -= 1
    X[C[t]+1][D[t]+1] += 1

# 二次元累積和をとる
for i in range(1, H+1):
	for j in range(1, W+1):
		Z[i][j] = Z[i][j-1] + X[i][j]
for j in range(1, W+1):
	for i in range(1, H+1):
		Z[i][j] = Z[i-1][j] + Z[i][j]

# 出力
for i in range(1, H+1):
	for j in range(1, W+1):
		if j >= 2:
			print(" ", end="")
		print(Z[i][j], end="")
	print("")
