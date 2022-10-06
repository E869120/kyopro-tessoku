INF = 1 << 61
class Edge:
    def __init__(self, to, cap, rev):
        self.to = to
        self.cap = cap
        self.rev = rev

class FordFulkerson:
    def __init__(self, N):
        self.size = N
        self.g = [[] for _ in range(N)]

    def add_edge(self, a, b, c):
        g = self.g
        e = Edge(b, c, None)
        rev = Edge(a, 0, e)
        e.rev = rev
        g[a].append(e)
        g[b].append(rev)

    def dfs(self, i, goal, F):
        # ゴールに到着
        if i == goal:
            return F

        self.visited[i] = True

        for e in self.g[i]:
            # 容量 0 の辺は使えない
            if e.cap == 0:
                continue
            # 既に訪問した頂点に行かない
            if self.visited[e.to]:
                continue
            # 目的地までのパスを探す
            flow = self.dfs(e.to, goal, min(F, e.cap))
            # フローを流せる場合、残余グラフの容量を flow だけ増減させる
            if flow:
                e.cap -= flow
                e.rev.cap += flow
                return flow
        # すべての辺を探索しても見つからなかった
        return 0

    def max_flow(self, s, t):
        ans = 0
        while True:
            self.visited = [False] * self.size
            F = self.dfs(s, t, INF)

            # フローを流せなくなったら操作終了
            if F == 0:
                break
            ans += F
        return ans

N, M = map(int, input().split())

# グラフを構築 (二部マッチング)
S = N + 24
T = S + 1
g = FordFulkerson(T + 1)

for i in range(N):
    C = input()
    g.add_edge(S, i, 10)
    for j, c in enumerate(C):
        if c == '1':
            g.add_edge(i, N + j, 1)
for j in range(24):
    g.add_edge(N + j, T, M)

print("Yes" if g.max_flow(S, T) == M * 24 else "No")
