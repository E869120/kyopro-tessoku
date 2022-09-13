import heapq

# 入力
N, M = map(int, input().split())
roads = [ list(map(int, input().split())) for i in range(M) ]

# グラフの作成
G = [ list() for i in range(N + 1) ]
for a, b, c, d in roads:
	if d == 1:
		G[a].append((b, 10000 * c - 1))
		G[b].append((a, 10000 * c - 1))
	else:
		G[a].append((b, 10000 * c))
		G[b].append((a, 10000 * c))

# ダイクストラ法（ダイクストラ法の詳しい説明については本書籍の 9.4 節、および ../chap09/answer_A64.py を参照）
INF = 10 ** 10
kakutei = [ False ] * (N + 1)
cur = [ INF ] * (N + 1)
cur[1] = 0
Q = []
heapq.heappush(Q, (cur[1], 1))
while len(Q) >= 1:
	pos = heapq.heappop(Q)[1]
	if kakutei[pos] == True:
		continue
	kakutei[pos] = True
	for e in G[pos]:
		if cur[e[0]] > cur[pos] + e[1]:
			cur[e[0]] = cur[pos] + e[1]
			heapq.heappush(Q, (cur[e[0]], e[0]))

# 答えを求めて出力
# マラソンコースの距離：cur[N] / 10000 を小数点以下切り上げた値
# コース上の木の数：cur[N] と distance * 10000 の差分
distance = (cur[N] + 9999) // 10000
num_trees = distance * 10000 - cur[N]
print(distance, num_trees)