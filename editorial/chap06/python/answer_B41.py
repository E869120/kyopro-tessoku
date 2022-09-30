# 入力
X, Y = map(int, input().split())

# 逆から考えていく
Answer = []
while X>=2 or Y>=2:
	Answer.append([X, Y])
	if X > Y:
		X -= Y
	else:
		Y -= X
Answer.reverse()

# 出力
print(len(Answer))
for i in range(len(Answer)):
	print(str(Answer[i][0]) + ' ' + str(Answer[i][1]))
