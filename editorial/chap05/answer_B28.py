# 入力
N = int(input())

# フィボナッチ数の計算
a = [ None ] * (N + 1)
a[1] = 1
a[2] = 1
for i in range(3, N+1):
	a[i] = (a[i-1] + a[i-2]) % 1000000007

# 出力
print(a[N])
