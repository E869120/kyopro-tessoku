import bisect

# 配列 A の最長増加部分列（LIS）の長さを計算する
# 配列 dp を使わない実装方法を利用している
def Get_LISvalue(A):
	LEN = 0
	L = []
	for i in range(N):
		pos = bisect.bisect_left(L, A[i])
		if pos == LEN:
			L.append(A[i])
			LEN += 1
		else:
			L[pos] = A[i]
	return LEN

# 入力
N = int(input())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# ソート
tmp = []
for i in range(N):
	tmp.append([X[i], -Y[i]])
tmp.sort()

# LIS を求めるべき配列は？
A = []
for i in range(N):
	A.append(-tmp[i][1])

# 出力
print(Get_LISvalue(A))
