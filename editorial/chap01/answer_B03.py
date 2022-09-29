# 入力
N = int(input())
A = list(map(int, input().split()))

# 答えを求める
Answer = False
for i in range(N):
	for j in range(i+1, N):
		for k in range(j+1, N):
			if A[i] + A[j] + A[k] == 1000:
				Answer = True

# 出力
if Answer == True:
	print("Yes")
else:
	print("No")
