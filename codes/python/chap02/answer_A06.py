N, Q = map(int, input().split())
A = list(map(int, input().split()))
L = [ None ] * Q
R = [ None ] * Q
for j in range(Q):
	L[j], R[j] = map(int, input().split())
 
S = [ None ] * (N + 1)
S[0] = 0
for i in range(N):
	S[i + 1] = S[i] + A[i]
 
for j in range(Q):
	print(S[R[j]] - S[L[j] - 1])
