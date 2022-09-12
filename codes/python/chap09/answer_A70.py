from collections import deque

# 入力（ここでは書籍とは異なり、ランプの番号が 0-indexed になるように実装しています）
N, M = map(int, input().split())
A = list(map(int, input().split()))
actions = [ list(map(lambda x: int(x) - 1, input().split())) for i in range(M) ] # ここでは X[i], Y[i], Z[i] を 0-indexed に変換して受け取る

# 頂点 pos の状態から「ランプ x, y, z の状態」を反転させたときの頂点番号を返す関数
def get_next(pos, x, y, z):
	# pos の 2 進法表記を使って、頂点 pos が表すランプの状態 state を計算
	# （pos の 2^i の位は (pos // (2 ** i)) % 2 で計算できる → 1.4 節を参照）
	state = [ (pos // (2 ** i)) % 2 for i in range(N) ]
	# ランプ x, y, z を反転
	state[x] = 1 - state[x]
	state[y] = 1 - state[y]
	state[z] = 1 - state[z]
	# ランプの状態 state を指す頂点の番号を計算
	# （2 進法を 10 進法に変換する方法は 1.4 節を参照）
	ret = 0
	for i in range(N):
		if state[i] == 1:
			ret += 2 ** i
	return ret

# グラフに辺を追加
G = [ list() for i in range(2 ** N) ]
for i in range(2 ** N):
	for x, y, z in actions:
		nextstate = get_next(i, x, y, z)
		G[i].append(nextstate)

# スタート地点・ゴール地点の頂点番号を決める
start = 0
for i in range(N):
	if A[i] == 1:
		start += 2 ** i
goal = 2 ** N - 1

# 幅優先探索の初期化
dist = [ -1 ] * (2 ** N)
dist[start] = 0
Q = deque()
Q.append(start)

# 幅優先探索
while len(Q) >= 1:
	pos = Q.popleft() # キュー Q の先頭要素を取り除き、その値を pos に代入する
	for nex in G[pos]:
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.append(nex)

# 答えを出力
print(dist[goal])

# 注意 1：この問題に対してはより簡潔な実装もありますので、
#         もしよければ answer_A70_extra.py もご覧ください。