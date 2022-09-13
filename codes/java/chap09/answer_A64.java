import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 入力（高速な入出力のため、Scanner の代わりに BufferedReader を使っています）
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		int[] C = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(buff.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
			C[i] = Integer.parseInt(st.nextToken());
		}
		
		// 隣接リストの作成
		ArrayList<Edge>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Edge>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(new Edge(B[i], C[i]));
			G[B[i]].add(new Edge(A[i], C[i]));
		}
		
		// 配列の初期化
		final int INF = 2000000000;
		boolean[] kakutei = new boolean[N + 1]; // Java では new で初期化した配列の要素は false になることに注意
		int[] cur = new int[N + 1];
		Arrays.fill(cur, INF);

		// スタート地点をキューに追加
		cur[1] = 0;
		Queue<State> Q = new PriorityQueue<>();
		Q.add(new State(cur[1], 1));

		// ダイクストラ法
		while (Q.size() >= 1) {
			// 次に確定させるべき頂点を求める
			// （ここでは、優先度付きキュー Q の最小要素を取り出し、これを Q から削除する）
			int pos = Q.remove().pos;

			// Q の最小要素が「既に確定した頂点」の場合
			if (kakutei[pos]) {
				continue;
			}

			// cur[x] の値を更新する
			kakutei[pos] = true;
			for (int i = 0; i < G[pos].size(); i++) {
				Edge e = G[pos].get(i);
				if (cur[e.to] > cur[pos] + e.cost) {
					cur[e.to] = cur[pos] + e.cost;
					Q.add(new State(cur[e.to], e.to));
				}
			}
		}
		
		// 答えを出力（高速な出力のため、System.out.println ではなく PrintWriter を使っています）
		PrintWriter output = new PrintWriter(System.out);
		for (int i = 1; i <= N; i++) {
			if (cur[i] != INF) {
				output.println(cur[i]);
			}
			else {
				output.println("-1");
			}
		}
		output.flush();
	}

	// 重み付きグラフの辺のクラス Edge
	static class Edge {
		int to, cost; // 行き先 to、長さ cost
		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	// ダイクストラ法の (cur[x], x) を管理するクラス（cur[x] = dist, x = pos に対応）
	static class State implements Comparable<State> {
		int dist, pos;
		public State(int dist, int pos) {
			this.dist = dist;
			this.pos = pos;
		}
		@Override public int compareTo(State s) {
			// State 型同士の比較をする関数
			if (this.dist < s.dist) {
				return -1;
			}
			if (this.dist > s.dist) {
				return 1;
			}
			return 0;
		}
	}
}
