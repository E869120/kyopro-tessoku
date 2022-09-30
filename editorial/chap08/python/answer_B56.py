mod = 2147483647

# 文字列の l～r 番目を前から読んだ時のハッシュ値を返す関数
def GetHashLeft(l: int, r: int) -> int:
	val = H[r] - Power100[r - l + 1] * H[l - 1]
	return val % mod

# 文字列の l～r 番目を後ろから読んだ時のハッシュ値を返す関数
def GetHashRight(l: int, r: int) -> int:
	l, r = N + 1 - r, N + 1 - l
	val = HRev[r] - Power100[r - l + 1] * HRev[l - 1]
	return val % mod

# 入力
N, Q = map(int, input().split())
S = input()
Query = [tuple(map(int, input().split())) for _ in range(Q)]

# S の各文字を数値に変換
S = list(S)
for i in range(N):
	S[i] = ord(S[i]) - ord('a') + 1
SRev = S[::-1]

# 100 の n 乗を前計算
Power100 = [1] * (N + 1)
for i in range(N):
	Power100[i + 1] = Power100[i] * 100 % mod

# S のハッシュ値を前計算
H = [1] * (N + 1)
for i in range(N):
	H[i + 1] = (H[i] * 100 + S[i]) % mod

# SRev のハッシュ値を前計算
HRev = [1] * (N + 1)
for i in range(N):
	HRev[i + 1] = (HRev[i] * 100 + SRev[i]) % mod

# クエリの処理
for L, R in Query:
	v1 = GetHashLeft(L, R)
	v2 = GetHashRight(L, R)
	# 左から読んだ時・右から読んだ時のハッシュ値が一致していれば回文
	if v1 == v2:
		print("Yes")
	else:
		print("No")
