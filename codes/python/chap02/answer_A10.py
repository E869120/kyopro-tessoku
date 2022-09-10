# 入力
N = int(input())
A = list(map(int, input().split()))
D = int(input())
L = [ None ] * D
R = [ None ] * D
for d in range(D):
	L[d], R[d] = map(int, input().split())

# P[i] を求める
# P[0] などになっているのは、配列が 0 始まりであるため
P = [ None ] * N
P[0] = A[0]
for i in range(1, N):
	P[i] = max(P[i-1], A[i])

# Q[i] を求める
# Q[N-1] などになっているのは、配列が 0 始まりであるため
Q = [ None ] * N
Q[N-1] = A[N-1]
for i in reversed(range(0,N-1)):
	Q[i] = max(Q[i+1], A[i])

# それぞれの日について答えを求める
# (L[d]-1)-1 などになっているのは、配列が 0 始まりであるため
for d in range(D):
	print(max(P[(L[d]-1)-1], Q[(R[d]+1)-1]))
