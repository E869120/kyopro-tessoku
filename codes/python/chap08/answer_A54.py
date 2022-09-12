# 入力
Q = int(input()) # クエリ数
queries = [ input().split() for i in range(Q) ] # クエリの情報（各要素は ["1", 名前を表す文字列, 得点を表す文字列] or ["2", 名前を表す文字列]）

# クエリの処理
Map = {}
for q in queries:
	if q[0] == "1":
		Map[q[1]] = q[2]
	if q[0] == "2":
		print(Map[q[1]])