# a の b 乗を m で割った余りを返す関数
def Power(a, b, m):
	p = a
	Answer = 1
	for i in range(30):
		wari = 2 ** i
		if (b // wari) % 2 == 1:
			Answer = (Answer * p) % m # a の 2^i 乗が掛けられるとき
		p = (p * p) % m
	return Answer

# a÷b を m で割った余りを返す関数
def Division(a, b, m):
	return (a * Power(b, m - 2, m)) % m

# 入力など
n, r = map(int, input().split())
M = 1000000007

# 手順 1：分子を求める
a = 1
for i in range(1, n + 1):
	a = (a * i) % M

# 手順 2：分母を求める
b = 1
for i in range(1, r+1):
	b = (b * i) % M
for i in range(1, n-r+1):
	b = (b * i) % M

# 手順 3：答えを求める
print(Division(a, b, M))
