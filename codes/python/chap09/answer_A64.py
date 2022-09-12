import heapq

# 入力
N, M = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(M) ]

# 隣接リストの作成（重み付きグラフなので、各辺について (隣接頂点, 重み) のタプルを記録する）
G = [ list() for i in range(N + 1) ]
for a, b, c in edges:
	G[a].append((b, c))
	G[b].append((a, c))

# 配列・キューの初期化（キューには (距離, 頂点番号) のタプルを記録する）
INF = 10 ** 10
kakutei = [ False ] * (N + 1)
cur = [ INF ] * (N + 1)
cur[1] = 0
Q = []
heapq.heappush(Q, (cur[1], 1))

# ダイクストラ法
while len(Q) >= 1:
	# 次に確定させるべき頂点を求める
	# （ここでは、優先度付きキュー Q の最小要素を取り除き、その要素の 2 番目の値（頂点番号）を pos に代入する）
	pos = heapq.heappop(Q)[1]

	# Q の最小要素が「既に確定した頂点」の場合
	if kakutei[pos] == True:
		continue
	
	# cur[x] の値を更新する
	kakutei[pos] = True
	for e in G[pos]:
		# 書籍内のコードとは pos = e[0], cost = e[1] で対応している
		if cur[e[0]] > cur[pos] + e[1]:
			cur[e[0]] = cur[pos] + e[1]
			heapq.heappush(Q, (cur[e[0]], e[0]))

# 答えを出力
for i in range(1, N + 1):
	if cur[i] != INF:
		print(cur[i])
	else:
		print("-1")