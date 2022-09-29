# 入力
N = int(input())
A = list(map(int, input().split()))
 
# 個数を数える
cnt = [ 0 ] * 100
for i in range(N):
	cnt[A[i] % 100] += 1
 
# 答えを求める
Answer = 0
for i in range(1, 50):
	Answer += cnt[i] * cnt[100-i]
Answer += cnt[0] * (cnt[0] - 1) // 2
Answer += cnt[50] * (cnt[50] - 1) // 2
 
# 出力
print(Answer)
