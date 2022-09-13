# 本プログラムでは、プログラムの実行速度を上げるため、numpy を使って 2 次元配列を計算しています。
# numpy で計算しやすくするために、B[i][j] は 100×100 の配列ではなく、左右に広げた 300×300 の配列を使って計算しています。
# プログラムは https://atcoder.jp/contests/future-contest-2018-qual/submissions/4216898 を参考に、本書籍のコードに基づいて実装しています。
# ※ 期待されるスコアは、およそ 99.940 億点です。
# ※ 焼きなまし法の実装は answer_A50_extra.py に載せています。

import numpy as np
import random
import time
import sys

# 定数の設定・入力
N = 100
Q = 1000
A = np.array([ list(map(int, input().split())) for i in range(N) ])

# 初期解を生成
X = [ random.randint(0, N - 1) for i in range(Q) ]
Y = [ random.randint(0, N - 1) for i in range(Q) ]
H = [ 1 ] * Q
B = np.zeros((3 * N, 3 * N))
for i in range(Q):
	B[Y[i]][X[i]] += 1

# H = 1, 2, ..., N に設定された場合の「増減分」を持った numpy 配列を作る
delta = [ None ] * (N + 1)
for i in range(1, N + 1):
	delta[i] = np.array([ [ max(i - abs(y) - abs(x), 0) for x in range(-i + 1, i) ] for y in range(-i + 1, i) ])

# 現在のスコアを取得する関数
def get_score():
	return 200000000 - np.absolute(A - B[N:2*N, N:2*N]).sum()

# 山登り法の設定
# （現在のスコアを np.absolute(A - B[N:2*N, N:2*N]).sum() として、これを最大化するという方法で実装する）
TIME_LIMIT = 5.4
current_score = get_score()
ti = time.time()

# 山登り法スタート
loops = 0
while time.time() - ti < TIME_LIMIT:
	# 「小さな変更」をランダムに選ぶ
	t = random.randint(0, Q - 1)
	old_x, new_x = X[t], X[t] + random.randint(-9, +9)
	old_y, new_y = Y[t], Y[t] + random.randint(-9, +9)
	old_h, new_h = H[t], H[t] + random.randint(-19, +19)
	if new_x < 0 or new_x >= N or new_y < 0 or new_y >= N or new_h <= 0 or new_h > N:
		continue
	
	# X[t] = new_x, Y[t] = new_y, H[t] = new_h に変更（書籍中の Change(t, new_x, new_y, new_h) の呼び出しに対応）
	B[N+Y[t]-H[t]+1:N+Y[t]+H[t], N+X[t]-H[t]+1:N+X[t]+H[t]] -= delta[H[t]]
	X[t], Y[t], H[t] = new_x, new_y, new_h
	B[N+Y[t]-H[t]+1:N+Y[t]+H[t], N+X[t]-H[t]+1:N+X[t]+H[t]] += delta[H[t]]

	# スコアを計算
	new_score = get_score()

	# スコアに応じて採用／不採用を決める
	if current_score < new_score:
		# 採用の場合
		current_score = new_score
	else:
		# 不採用の場合：X[t] = old_x, Y[t] = old_y, H[t] = old_h に戻す（書籍中の Change(t, old_x, old_y, old_h) の呼び出しに対応）
		B[N+Y[t]-H[t]+1:N+Y[t]+H[t], N+X[t]-H[t]+1:N+X[t]+H[t]] -= delta[H[t]]
		X[t], Y[t], H[t] = old_x, old_y, old_h
		B[N+Y[t]-H[t]+1:N+Y[t]+H[t], N+X[t]-H[t]+1:N+X[t]+H[t]] += delta[H[t]]
	
	loops += 1

# 出力
print(Q)
for i in range(Q):
	print(X[i], Y[i], H[i])
print("score =", current_score, file = sys.stderr)
print("loops =", loops, file = sys.stderr)
