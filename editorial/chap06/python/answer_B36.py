# 入力
N, K = map(int, input().split())
S = input()

# ON となっているものの個数を数える
numON = 0
for i in range(N):
	if S[i] == '1':
		numON += 1

# 答えを出力
if numON%2 == K%2:
	print("Yes")
else:
	print("No")
