# 入力
S = input()

# 左から順番に見ていく
# 文字列は 0 文字目から始まることに注意
Stack = []
for i in range(len(S)):
	if S[i] == '(':
		Stack.append(i + 1)
	if S[i] == ')':
		print(Stack.pop(), i + 1)
