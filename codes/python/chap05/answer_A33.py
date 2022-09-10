# 入力
N = int(input())
A = list(map(int, input().split()))

# 全部 XOR した値（ニム和）を求める
XOR_Sum = A[0]
for i in range(1,N):
	XOR_Sum = (XOR_Sum ^ A[i])

# 出力
if XOR_Sum >= 1:
	print("First")
else:
	print("Second")
