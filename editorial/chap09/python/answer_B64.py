from heapq import heappush, heappop

N, M = map(int, input().split())
g = [[] for _ in range(N)]
for _ in range(M):
    A, B, C = map(int, input().split())
    A -= 1
    B -= 1
    g[A].append((B, C))
    g[B].append((A, C))

INF = 1 << 61
cost = [INF] * N
back = [-1] * N
q = []

# 頂点に訪れる部分を関数に切り出す
def push(prev: int, i: int, c: int):
    if cost[i] <= c:
        return
    cost[i] = c
    back[i] = prev
    heappush(q, (c, i))

# 復元の都合上後ろから Dijkstra 法
push(-1, N - 1, 0)
while q:
    c, x = heappop(q)
    if cost[x] != c:
        continue # 同じ頂点から複数回探索しない (worst Θ(N^2) 時間になります)
    for j, d in g[x]:
        push(x, j, c + d)

# 最短経路を復元
ans = [0]
while ans[-1] != N - 1:
    ans.append(back[ans[-1]])

for x in ans:
    print(x + 1)