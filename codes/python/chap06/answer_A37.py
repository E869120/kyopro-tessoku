# 入力
N, M, B = map(int, input().split())
A = list(map(int, input().split()))
C = list(map(int, input().split()))

# 答えの計算
Answer = 0
for i in range(N):
	Answer += A[i] * M
Answer += B * N * M
for j in range(M):
	Answer += C[j] * N

# 出力
print(Answer)
