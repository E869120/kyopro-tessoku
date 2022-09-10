# 入力
N = int(input())

# 上の桁から順番に「2 進法に変換した値」を求める
for x in [9,8,7,6,5,4,3,2,1,0]:
	wari = (2 ** x)
	print((N // wari) % 2, end='')

# 最後に改行する
print("")
