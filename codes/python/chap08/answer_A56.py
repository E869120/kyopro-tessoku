# 入力
N, Q = map(int, input().split())
S = input()
queries = [ list(map(int, input().split())) for i in range(Q) ]

# 文字を数値に変換（ここでは書籍とは異なり、0-indexed で実装しています）
# ord(c) で文字 c の文字コード（ASCII コード）を取得
T = list(map(lambda c: ord(c) - ord('a') + 1, S))

# 100 の n 乗を前計算
MOD = 2147483647
power100 = [ None ] * (N + 1)
power100[0] = 1
for i in range(N):
	power100[i + 1] = power100[i] * 100 % MOD

# H[1], H[2], ..., H[N] を計算する
H = [ None ] * (N + 1)
H[0] = 0
for i in range(N):
	H[i + 1] = (H[i] * 100 + T[i]) % MOD

# ハッシュ値を求める関数
# S[l-1:r] のハッシュ値は (H[r] - H[l - 1] * power100[r - l + 1]) % MOD で計算
# C++ とは異なり、（負の値）% M (M >= 1) も 0 以上 M-1 以下になることに注意
def hash_value(l, r):
	return (H[r] - H[l - 1] * power100[r - l + 1]) % MOD

# クエリに答える
for a, b, c, d in queries:
	hash1 = hash_value(a, b)
	hash2 = hash_value(c, d)
	if hash1 == hash2:
		print("Yes")
	else:
		print("No")
