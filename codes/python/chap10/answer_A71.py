# 入力
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 配列のソート（A は昇順に、B は降順にソート）
A.sort()
B.sort(reverse = True)

# 答えは A[i] * B[i] の総和
print(sum([ A[i] * B[i] for i in range(N) ]))