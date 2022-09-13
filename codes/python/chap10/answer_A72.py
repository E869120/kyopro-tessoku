import itertools

# 入力
H, W, K = map(int, input().split())
c = [ input() for i in range(H) ]

# 残り remaining_steps 回の「列に対する操作」で、最大何個のマスを黒くできるかを返す関数
def paint_row(H, W, d, remaining_steps):
	# 各列に対して (白マスの個数, 列の番号) のタプルを記録し、大きい順にソートする
	column = [ ([ d[i][j] for i in range(H) ].count('.'), j) for j in range(W) ]
	column.sort(reverse = True)

	# 列に対して操作を行う
	for j in range(remaining_steps):
		idx = column[j][1]
		for i in range(H):
			d[i][idx] = '#'
	
	# 黒マスの個数を数えて、これを返す
	return sum(map(lambda l: l.count('#'), d))

# 行の塗り方を全探索
# （ここでは「ビット全探索」ではなく itertools.product を使って 2^H 通りの塗り方を全列挙しています）
answer = 0
for v in itertools.product([ 0, 1 ], repeat = H):
	# 行に対して操作を行う（paint_row 関数でいくつかの d[i][j] を書き換えるため、d は string の配列ではなく 2 次元リストにしています）
	d = [ list(c[i]) for i in range(H) ]
	remaining_steps = K
	for i in range(H):
		if v[i] == 1:
			d[i] = [ '#' ] * W
			remaining_steps -= 1
	if remaining_steps >= 0:
		subanswer = paint_row(H, W, d, remaining_steps)
		answer = max(answer, subanswer)

# 出力
print(answer)