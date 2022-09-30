# 入力
A, B = map(int, input().split())

# 答えを求める
Answer = False
for i in range(A, B + 1):
	if 100 % i == 0:
		Answer = True

# 出力
if Answer == True:
	print("Yes")
else:
	print("No")
