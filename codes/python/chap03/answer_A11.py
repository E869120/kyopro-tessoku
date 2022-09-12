# 整数 x が何番目に存在するかを返す関数
def search(x, A):
	L = 0
	R = N-1
	while L <= R:
		M = (L + R) // 2
		if x < A[M]:
			R = M - 1
		if x == A[M]:
			return M
		if x > A[M]:
			L = M + 1
	return -1 # 整数 x が存在しない（注：この問題の制約で -1 が返されることはない）


# 入力（配列 X が 0 番目から始まることに注意）
N, X = map(int, input().split())
A = list(map(int, input().split()))

# 二分探索を行う（配列が 0 番目から始まるので、答えに 1 を足している）
Answer = search(X, A)
print(Answer + 1)
