# 二次元の点を扱うクラス
class point2d:
	def __init__(self, x, y):
		self.x = x
		self.y = y
	# 2 点間の距離を求める関数
	def dist(self, p):
		return ((self.x - p.x) ** 2 + (self.y - p.y) ** 2) ** 0.5

# 貪欲法によって答えを求める関数
# （ここでは都市の番号を 0-indexed で扱っていることに注意）
def play_greedy(n, points):
	# 配列などの初期化
	current_place = 0
	visited = [ False ] * n
	visited[0] = True
	P = [ 0 ]
	# 貪欲法スタート
	for i in range(1, n):
		mindist = 10 ** 10 # 現時点での距離の最小
		min_id = -1 # 次はどの都市に移動すればよいか
		# 距離が最小となる都市を探す
		for j in range(n):
			if not visited[j] and mindist > points[current_place].dist(points[j]):
				mindist = points[current_place].dist(points[j])
				min_id = j
		# 現在位置の更新
		visited[min_id] = True
		P.append(min_id)
		current_place = min_id
	# 最後に訪問する都市
	P.append(0)
	return P

# 入力
N = int(input())
points = [ None ] * N
for i in range(N):
	x, y = map(int, input().split())
	points[i] = point2d(x, y)

# 貪欲法
answer = play_greedy(N, points)

# 答えを出力（配列 answer の要素は 0-indexed になっていることに注意）
for i in answer:
	print(i + 1)