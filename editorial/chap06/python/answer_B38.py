# 入力
N = int(input())
S = input()

# 配列の準備
ret1 = [ None ] * N
ret2 = [ None ] * N

# 答えを求める（前半）
streak1 = 1 # streak1 は「何個 A が連続したか」+ 1
ret1[0] = 1
for i in range(N-1):
	if S[i] == 'A':
		streak1 += 1
	if S[i] == 'B':
		streak1 = 1
	ret1[i+1] = streak1

# 答えを求める（後半）
streak2 = 1
ret2[N-1] = 1
for i in reversed(range(N-1)):
	if S[i] == 'A':
		streak2 = 1
	if S[i] == 'B':
		streak2 += 1
	ret2[i] = streak2

# 出力
Answer = 0
for i in range(N):
	Answer += max(ret1[i], ret2[i])
print(Answer)
