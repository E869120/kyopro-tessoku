import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String[] C = new String[N + 1];
		for (int i = 0; i < N; i++) {
			C[i + 1] = sc.next();
		}

		// グラフを構成する
		MaximumFlow Z = new MaximumFlow(2 * N + 2);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (C[i].charAt(j - 1) == '#') {
					Z.addEdge(i, j + N, 1);
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			Z.addEdge(2 * N + 1, i, 1);     // 「s → 青色」の辺
			Z.addEdge(i + N, 2 * N + 2, 1); // 「赤色 → t」の辺
		}

		// 答えを求めて出力
		int answer = Z.maxFlow(2 * N + 1, 2 * N + 2);
		System.out.println(answer);
	}
	
	// 最大フローを求める用の辺のクラス FlowEdge
	static class FlowEdge {
		int to, cap, rev;
		public FlowEdge(int to, int cap, int rev) {
			this.to = to;
			this.cap = cap;
			this.rev = rev;
		}
	}

	// 最大フローを行うクラス MaximumFlow
	static class MaximumFlow {
		int n;
		boolean[] used;
		ArrayList<FlowEdge>[] G;

		// 頂点数 N の残余グラフを準備
		public MaximumFlow(int n) {
			this.n = n;
			used = new boolean[n + 1];
			G = new ArrayList[n + 1];
			for (int i = 1; i <= n; i++) {
				G[i] = new ArrayList<FlowEdge>();
			}
		}

		// 頂点 a から b に向かう、上限 c リットル／秒の辺を追加
		void addEdge(int a, int b, int c) {
			int currentGa = G[a].size();
			int currentGb = G[b].size();
			G[a].add(new FlowEdge(b, c, currentGb));
			G[b].add(new FlowEdge(a, 0, currentGa));
		}

		// 深さ優先探索（F はスタートから pos に到達する過程での " 残余グラフの辺の容量 " の最小値）
		// 返り値は流したフローの量（流せない場合は 0 を返す）
		int dfs(int pos, int goal, int F) {
			// ゴールに到着：フローを流せる！
			if (pos == goal) {
				return F;
			}
			used[pos] = true;
			// 探索する
			for (int i = 0; i < G[pos].size(); i++) {
				FlowEdge e = G[pos].get(i);
				// 容量 0 の辺は使えない
				if (e.cap == 0) {
					continue;
				}
				// 既に訪問した頂点に行っても意味がない
				if (used[e.to]) {
					continue;
				}
				// 目的地までのパスを探す
				int flow = dfs(e.to, goal, Math.min(F, e.cap));
				// フローを流せる場合、残余グラフの容量を flow だけ増減させる
				if (flow >= 1) {
					G[pos].get(i).cap -= flow;
					G[e.to].get(e.rev).cap += flow;
					return flow;
				}
			}
			// すべての辺を探索しても見つからなかった…
			return 0;
		}

		// 頂点 s から頂点 t までの最大フローの総流量を返す
		int maxFlow(int s, int t) {
			final int INF = 1000000000;
			int totalFlow = 0;
			while (true) {
				Arrays.fill(used, false);
				int f = dfs(s, t, INF);
				// フローを流せなくなったら操作終了
				if (f == 0) {
					break;
				}
				totalFlow += f;
			}
			return totalFlow;
		}
	}
}