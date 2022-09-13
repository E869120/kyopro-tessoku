import math
import random

# 二次元の点を扱うクラス
class point2d:
	def __init__(self, x, y):
		self.x = x
		self.y = y
	# 2 点間の距離を求める関数
	def dist(self, p):
		return ((self.x - p.x) ** 2 + (self.y - p.y) ** 2) ** 0.5

# 合計距離を計算する関数
def get_score(n, points, P):
	score = 0
	for i in range(n):
		score += points[P[i]].dist(points[P[i + 1]])
	return score

# 焼きなまし法によって答えを求める関数
# （ここでは都市の番号を 0-indexed で扱っていることに注意）
def simulated_annealing(n, points):
	# 初期解生成
	P = [ i % n for i in range(n + 1) ]
	current_score = get_score(n, points, P)
	# 焼きなまし法
	NUM_LOOPS = 150000
	for t in range(NUM_LOOPS):
		# 反転させる区間 [L, R] を選ぶ
		l = random.randint(1, n - 1) # 1 以上 n-1 以下のランダムな整数
		r = random.randint(1, n - 1) # 1 以上 n-1 以下のランダムな整数
		if l > r:
			l, r = r, l
		# P[l], P[l+1], ..., P[r] を逆順にしたときの合計距離 new_score を求める
		# （現在の合計距離との差分を考える）
		new_score = current_score
		new_score -= points[P[l - 1]].dist(points[P[l]])
		new_score -= points[P[r]].dist(points[P[r + 1]])
		new_score += points[P[l - 1]].dist(points[P[r]])
		new_score += points[P[l]].dist(points[P[r + 1]])
		# 7.2 節の解答例から変更した唯一の部分（probability は採用確率）
		# （random.random() で 0 以上 1 未満のランダムな実数を生成）
		T = 30 - 28 * (t / NUM_LOOPS)
		probability = math.exp(min((current_score - new_score) / T, 0))
		if random.random() < probability:
			# 解が改善したときのみ P を更新する
			P[l:r+1] = reversed(P[l:r+1])
			current_score = new_score
	return P

# 入力
N = int(input())
points = [ None ] * N
for i in range(N):
	x, y = map(int, input().split())
	points[i] = point2d(x, y)

# 焼きなまし法
answer = simulated_annealing(N, points)

# 答えを出力（配列 answer の要素は 0-indexed になっていることに注意）
for i in answer:
	print(i + 1)

# 注意 1：このプログラムを PyPy3 で提出すると、ループを 150,000 回程度回すことができます。これは answer_A48.py と比べて約 4 倍です。
#         ヒューリスティックの問題では、実行速度を改善することでスコアや順位が大幅に上がることがよくあります。
# 注意 2：このプログラムが高速な理由は、解が実際に改善するまでは P の区間を実際に反転せず、差分をたよりに new_score を見積もっているので、
#         解が改善しないときの 1 回のループの計算量が O(1) になっているからです。