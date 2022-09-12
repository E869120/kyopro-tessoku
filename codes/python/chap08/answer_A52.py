from collections import deque

# 入力
Q = int(input()) # クエリ数
queries = [ input().split() for i in range(Q) ] # クエリの情報（各要素は ["1", 名前を表す文字列] or ["2"] or ["3"]）

# クエリの処理
T = deque()
for q in queries:
	if q[0] == "1":
		T.append(q[1])
	if q[0] == "2":
		print(T[0])
	if q[0] == "3":
		T.popleft()