###########################
# 配列 dp を使わない実装 
###########################

import bisect

# 入力（A は 0 番目から始まることに注意！）
N = int(input())
A = list(map(int, input().split()))

# 動的計画法の準備
LEN = 0
L = []

# 動的計画法（配列 dp を使った実装）
for i in range(N):
	pos = bisect.bisect_left(L, A[i])
	if pos >= LEN:
		L.append(A[i])
		LEN += 1
	else:
		L[pos] = A[i]

# 答えを出力
print(LEN)
