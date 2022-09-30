# omote=1 のとき表の総和が正、ura=1 のとき裏の総和が正
# omote=2 のとき表の総和が負、ura=2 のとき裏の総和が負
def solve(omote, ura, A, B):
	sum = 0
	for i in range(N):
		card1 = A[i]
		if omote == 2:
			card1 = -A[i]
		card2 = B[i]
		if ura == 2:
			card2 = -B[i]
		# カード i は選ぶべきか？
		if card1 + card2 >= 0:
			sum += (card1 + card2)
	return sum

# 入力
N = int(input())
A = [ None ] * N
B = [ None ] * N
for i in range(N):
	A[i], B[i] = map(int, input().split())

# 表の総和の正負と、裏の総和の正負を全探索
Answer1 = solve(1, 1, A, B);
Answer2 = solve(1, 2, A, B);
Answer3 = solve(2, 1, A, B);
Answer4 = solve(2, 2, A, B);

# 出力
print(max(Answer1, Answer2, Answer3, Answer4))
