siz = 1 << 18
dat = [0] * (siz * 2)

# 代入 seg[i] = v
def update(i: int, v: int) -> None:
	i += siz
	dat[i] = v
	while i > 1:
		i >>= 1
		dat[i] = dat[i * 2] + dat[i * 2 + 1]

# sum(seg[l], seg[l + 1], ..., seg[r - 1]) を求める
def query(l: int, r: int) -> int:
	l += siz
	r += siz
	answer = 0
	while l < r:
		if l & 1:
			answer += dat[l]
			l += 1
		if r & 1:
			r -= 1
			answer += dat[r]
		l >>= 1
		r >>= 1
	return answer

# 入力
N = int(input())
A = list(map(int, input().split()))

# 答えを求める
Answer = 0
for a in A:
	Answer += query(a + 1, siz)
	update(a, 1)

# 出力
print(Answer)
