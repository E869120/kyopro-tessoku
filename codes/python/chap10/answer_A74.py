# 入力
N = int(input())
P = [ list(map(int, input().split())) for i in range(N) ]

# 「転倒数を求める問題」2 つに分解する
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	for j in range(N):
		if P[i][j] != 0:
			X[i] = P[i][j]
			Y[j] = P[i][j]

# 転倒数を求める関数
def inversion(A):
	answer = 0
	for i in range(len(A)):
		for j in range(i + 1, len(A)):
			if A[i] > A[j]:
				answer += 1
	return answer

# 答えを出力
print(inversion(X) + inversion(Y))