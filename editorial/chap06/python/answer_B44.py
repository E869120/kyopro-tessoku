# 入力
N = int(input())
A = [ None ] * N
for i in range(N):
	A[i] = list(map(int, input().split()))

# 配列 T を初期化
# 配列 A が 0 始まりなので、配列 T も 0 始まり
T = [ None ] * N
for i in range(N):
	T[i] = i

# クエリの処理
Q = int(input())
for i in range(Q):
	Query = list(map(int, input().split()))
	if Query[0] == 1:
		T[Query[1]-1],T[Query[2]-1] = T[Query[2]-1],T[Query[1]-1]
	if Query[0] == 2:
		print(A[T[Query[1]-1]][Query[2]-1])
