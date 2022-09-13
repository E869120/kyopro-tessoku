# 入力
N, L = map(int, input().split())
K = int(input())
A = list(map(int, input().split()))

# スコアの最大値が x 以上かを判定する関数
def check(x):
	cnt = 0         # 現時点で何回切ったかを表す
	last_kireme = 0 # 最後どこで切ったかを表す
	for i in range(N):
		if A[i] - last_kireme >= x and L - A[i] >= x:
			cnt += 1
			last_kireme = A[i]
	return cnt >= K

# 二分探索（left: 現在の上限 ／ right: 現在の下限）
left, right = 1, 10 ** 9
while left < right:
	mid = (left + right + 1) // 2
	answer = check(mid)
	if answer == False:
		right = mid - 1 # 答えが前半部分に絞られる
	else:
		left = mid      # 答えが後半部分に絞られる

# 出力
print(left)