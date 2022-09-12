# 入力
N, M = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(M) ]

# 隣接リストの作成
G = [ list() for i in range(N + 1) ] # G[i] は頂点 i に隣接する頂点のリスト
for a, b in edges:
	G[a].append(b) # 頂点 a に隣接する頂点として b を追加
	G[b].append(a) # 頂点 b に隣接する頂点として a を追加

# 出力
for i in range(1, N + 1):
	output = ''
	output += str(i)
	output += ': {'
	output += ', '.join(map(str, G[i])) # 例えば G[i] = { 2, 7, 5 } のとき、ここで "2, 7, 5" という文字列が output の後ろに連結される
	output += '}'
	print(output)