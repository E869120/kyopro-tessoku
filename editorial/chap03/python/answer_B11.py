import bisect

# 入力
N = int(input())
A = list(map(int, input().split()))
Q = int(input())
X = [ None ] * Q
for i in range(Q):
	X[i] = int(input())

# 配列 X をソート
A.sort()

# 質問に答える（配列 A は 0 番目から始まっていることに注意！）
for i in range(Q):
	pos1 = bisect.bisect_left(A, X[i])
	print(pos1)
