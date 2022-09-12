from collections import deque

# 入力（ここでは書籍とは異なり、ランプの番号が 0-indexed になるように実装しています）
N, M = map(int, input().split())
A = list(map(int, input().split()))
actions = [ list(map(lambda x: int(x) - 1, input().split())) for i in range(M) ] # ここでは X[i], Y[i], Z[i] を 0-indexed に変換して受け取る

# スタート地点・ゴール地点の頂点番号を決める
start = sum(A[i] * (2 ** i) for i in range(N))
goal = 2 ** N - 1

# 幅優先探索の初期化
dist = [ -1 ] * (2 ** N)
dist[start] = 0
Q = deque()
Q.append(start)

# 幅優先探索
# （ここではグラフを実際に持たずに、pos から出る辺をそのまま計算して幅優先探索を行います）
while len(Q) >= 1:
	pos = Q.popleft() # キュー Q の先頭要素を取り除き、その値を pos に代入する
	for x, y, z in actions:
		# ビット演算の XOR を使います（XOR についてはコラム 1 を参照）。
		# ランプ k を反転することは、頂点番号の 2^k の位を反転すること、すなわち 2^k を XOR することと同じになります。
		nex = pos ^ (1 << x) ^ (1 << y) ^ (1 << z)
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.append(nex)

# 答えを出力
print(dist[goal])

# 注意 1：ビット演算は、掛け算 (*)、割り算 (//)、累乗 (**) などの演算と比べて高速であるため、
#         このプログラムは answer_A70.py と比較して約 1/5 の実行時間で答えが出せます。