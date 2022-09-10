# 整数の組 (a, b) が決まったときの、参加可能な生徒数を返す関数
def GetScore(a, b, A, B, K):
	cnt = 0
	for i in range(N):
		if a <= A[i] and A[i] <= a + K and b <= B[i] and B[i] <= b+K:
			cnt += 1
	return cnt

# 入力
N, K = map(int, input().split())
A = [ None ] * N
B = [ None ] * N
for i in range(N):
	A[i], B[i] = map(int, input().split())

# (a, b) の組を全探索
Answer = 0
for a in range(1, 101):
	for b in range(1, 101):
		Score = GetScore(a, b, A, B, K)
		Answer = max(Answer, Score)

# 出力
print(Answer)
