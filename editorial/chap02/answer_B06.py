# 入力
N = int(input())
A = list(map(int, input().split()))
Q = int(input())
L = [ None ] * Q
R = [ None ] * Q
for i in range(Q):
	L[i], R[i] = map(int, input().split())

# アタリの個数・ハズレの個数の累積和を求める
# 配列 A が 0 番目から始まっていることに注意！
Atari = [ 0 ] * (N + 1)
Hazre = [ 0 ] * (N + 1)
for i in range(1, N+1):
	# アタリについて計算
	Atari[i] = Atari[i - 1]
	if A[i - 1] == 1:
		Atari[i] += 1
	# ハズレについて計算
	Hazre[i] = Hazre[i - 1]
	if A[i - 1] == 0:
		Hazre[i] += 1

# 質問に答える
for i in range(Q):
	NumAtari = Atari[R[i]] - Atari[L[i] - 1]
	NumHazre = Hazre[R[i]] - Hazre[L[i] - 1]
	if NumAtari > NumHazre:
		print("win")
	elif NumAtari == NumHazre:
		print("draw")
	else:
		print("lose")
