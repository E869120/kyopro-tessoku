# 入力
N, X, Y = map(int, input().split())
A = list(map(int, input().split()))

# Grundy 数を求める
# 変数 grundy[i] : 石が i 個の時の Grundy 数
# 変数 Transit[i]: Grundy 数が i となるような遷移ができるか
grundy = [ None ] * 100001
for i in range(100001):
	Transit = [False, False, False]
	if i >= X:
		Transit[grundy[i-X]] = True
	if i >= Y:
		Transit[grundy[i-Y]] = True

	if Transit[0] == False:
		grundy[i] = 0
	elif Transit[1] == False:
		grundy[i] = 1
	else:
		grundy[i] = 2

# 出力
XOR_Sum = 0
for i in range(N):
	XOR_Sum = (XOR_Sum ^ grundy[A[i]])
if XOR_Sum >= 1:
	print("First")
else:
	print("Second")
