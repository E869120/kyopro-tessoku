# 入力
N = int(input())

# エラトステネスのふるい
# 整数 x が消されている場合に限り Deleted[x]=true
Deleted = [ False ] * 1000009
LIMIT = int(N ** 0.5)
for i in range(2, LIMIT+1):
	if Deleted[i] == False:
		for j in range(i*2, N+1, i):
			Deleted[j] = True

# 答えを出力
for i in range(2, N+1):
	if Deleted[i] == False:
		print(i)
