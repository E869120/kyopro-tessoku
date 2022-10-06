# 入力
H, W = map(int, input().split())
sx, sy = map(int, input().split())
sx -= 1
sy -= 1
gx, gy = map(int, input().split())
gx -= 1
gy -= 1
S = [input() for _ in range(H)]

INF = 1 << 61
# Python では多次元配列は 1 次元に flatten した方が速い (ここでは使わない)
cost = [[INF] * W for _ in range(H)]

q = [] # queue は list で再現できる
# マスに訪れる部分を関数に切り出すと良い
def push(x: int, y: int, c: int):
    if S[x][y] == '#':
        return
    if cost[x][y] <= c:
        return
    cost[x][y] = c
    q.append((x, y))

# 幅優先探索
push(sx, sy, 0)
for x, y in q:
    c2 = cost[x][y] + 1
    push(x - 1, y, c2)
    push(x, y - 1, c2)
    push(x + 1, y, c2)
    push(x, y + 1, c2)

print(cost[gx][gy])
