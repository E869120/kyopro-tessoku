from collections import deque

# 入力
N, M = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(M) ]

# 隣接リストの作成
G = [ list() for i in range(N + 1) ]
for a, b in edges:
	G[a].append(b)
	G[b].append(a)

# 幅優先探索の初期化（dist[i] = ? ではなく dist[i] = -1 で初期化していることに注意）
dist = [ -1 ] * (N + 1)
dist[1] = 0
Q = deque()
Q.append(1)

# 幅優先探索
while len(Q) >= 1:
	pos = Q.popleft() # キュー Q の先頭要素を取り除き、その値を pos に代入する
	for nex in G[pos]:
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.append(nex)

# 頂点 1 から各頂点までの最短距離を出力
for i in range(1, N + 1):
	print(dist[i])