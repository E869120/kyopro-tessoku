import sys
sys.setrecursionlimit(1 << 20)  # 再帰上限がデフォルトで 1000 なので変更する

# 入力
N, M = map(int, input().split())
g = [[] for _ in range(N)]
for i in range(M):
    A, B = map(int, input().split())
    A -= 1
    B -= 1
    g[A].append(B)
    g[B].append(A)

# 深さ優先探索
visited = [False] * (N + 1)
path = []

def dfs(i: int):
    path.append(i)
    # ゴール地点にたどり着いた！
    if i == N - 1:
        # 答えを出力して終了
        for x in path:
            print(x + 1) # 1-indexed に変更
        exit(0)

    # その他の場合
    visited[i] = True
    for j in g[i]:
        if not visited[j]:
            dfs(j)
    path.pop()

dfs(0)
