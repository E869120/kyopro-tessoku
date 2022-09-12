from collections import deque

# 入力
N = int(input())
A = list(map(int, input().split()))

# スタックの変化の再現
# （スタックには (日付, 株価) のタプルを記録する）
answer = [ None ] * N
level2 = deque()
for i in range(N):
	if i >= 1:
		level2.append((i, A[i - 1]))
		while len(level2) >= 1:
			kabuka = level2[-1][1] # 株価はタプルの 2 番目の要素
			if kabuka <= A[i]:
				level2.pop()
			else:
				break
	if len(level2) >= 1:
		answer[i] = level2[-1][0] # 日付はタプルの 1 番目の要素
	else:
		answer[i] = -1

# answer を空白区切りで出力
print(*answer)