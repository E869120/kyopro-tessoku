Map = {}
 
# 入力
N = int(input())
A = [int(input()) for _ in range(N)]

# 答えを求める
Answer = 0
for a in A:
	# dict.get にはキーが存在しなかった場合のデフォルト値を設定できる
	Answer += Map.get(a, 0)
	Map[a] = Map.get(a, 0) + 1

# 出力
print(Answer)
