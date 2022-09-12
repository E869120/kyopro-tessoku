import copy

# 1 回の操作 (P[i], Q[i], R[i]) を表す構造体
class round:
	def __init__(self, p, q, r):
		self.p = p
		self.q = q
		self.r = r

# 盤面の状態を表す構造体
class state:
	# 盤面の状態の初期化
	def __init__(self, n):
		self.score = 0      # 暫定スコア
		self.x = [ 0 ] * n  # 現在の配列 X の値
		self.lastmove = '?' # 最後の動き（'A' または 'B'、ただし初期状態では '?' としておく）
		self.lastpos = -1   # Beam[i-1][どこ] から遷移したか（ただし初期状態では -1 としておく）

# ビームサーチを行う関数
def beam_search(N, T, rounds):
	# 2 次元配列 beam を用意し、0 手目の状態を設定
	WIDTH = 10000
	beam = [ list() for i in range(T + 1) ]
	beam[0].append(state(N))

	# ビームサーチ
	for i in range(T):
		candidate = list()
		for j in range(len(beam[i])):
			# 操作 A の場合
			sousa_a = copy.deepcopy(beam[i][j])
			sousa_a.lastmove = 'A'
			sousa_a.lastpos = j
			sousa_a.x[rounds[i].p] += 1
			sousa_a.x[rounds[i].q] += 1
			sousa_a.x[rounds[i].r] += 1
			sousa_a.score += sousa_a.x.count(0) # スコアに「sousa_a.x に含まれる 0 の個数」を加算
			# 操作 B の場合
			sousa_b = copy.deepcopy(beam[i][j])
			sousa_b.lastmove = 'B'
			sousa_b.lastpos = j
			sousa_b.x[rounds[i].p] -= 1
			sousa_b.x[rounds[i].q] -= 1
			sousa_b.x[rounds[i].r] -= 1
			sousa_b.score += sousa_b.x.count(0) # スコアに「sousa_a.x に含まれる 0 の個数」を加算
			# 候補に追加
			candidate.append(sousa_a)
			candidate.append(sousa_b)
		# ソートして beam[i+1] の結果を計算する
		candidate.sort(key = lambda s: -s.score)
		beam[i + 1] = copy.deepcopy(candidate[:WIDTH]) # 多くとも candidate の上位 WIDTH 件しか記録しない
	
	# ビームサーチの復元
	current_place = 0
	answer = [ None ] * T
	for i in range(T, 0, -1):
		answer[i - 1] = beam[i][current_place].lastmove
		current_place = beam[i][current_place].lastpos
	return answer


# 入力
T = int(input())
rounds = [ None ] * T
for i in range(T):
	p, q, r = map(int, input().split())
	rounds[i] = round(p - 1, q - 1, r - 1) # 書籍とは異なり、ここでは 0-indexed にするために 1 を引いています

# ビームサーチを行って答えを出す（書籍とは異なり、ビームサーチの復元は関数の中で行う）
answer = beam_search(20, T, rounds)

# 出力
for c in answer:
	print(c)

# 注意 1：このプログラムは、Python で提出するとビーム幅 200 程度、PyPy3 で提出するとビーム幅 350 程度で、実行時間制限の 1 秒ギリギリになります。
# 注意 2：ここでは deepcopy 関数を使っていますが、これが実行速度を遅くする原因となっています。
#         これを使わずに実装すると、プログラムがより高速になり、ビーム幅をより大きくすることができます。考えてみましょう。