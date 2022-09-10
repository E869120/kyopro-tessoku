# 入力
N = int(input())
A = list(map(int, input().split()))

# 個数を数える
cnt = [ 0 ] * 101
Answer = 0
for i in range(N):
	cnt[A[i]] += 1

# 答えを求める
for i in range(1, 101):
	Answer += cnt[i] * (cnt[i]-1) * (cnt[i]-2) // 6;
print(Answer)
