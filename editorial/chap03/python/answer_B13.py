# A[l] から A[r] までの合計値
def sum(l, r, S):
	return S[r+1] - S[l]

# 入力
N, K = map(int, input().split())
A = list(map(int, input().split()))

# 累積和をとる
S = [ 0 ] * (N + 1)
for i in range(1, N+1):
	S[i] = S[i-1] + A[i-1]

# 配列の準備（R は 0 番目から始まることに注意）
R = [ None ] * N

# しゃくとり法
for i in range(N):
	if i == 0:
		R[i] = -1
	else:
		R[i] = R[i - 1]
	while R[i] < N-1 and sum(i,R[i]+1,S) <= K:
		R[i] += 1

# 答えを求める
Answer = 0
for i in range(N):
	Answer += (R[i] - i + 1)
print(Answer)
