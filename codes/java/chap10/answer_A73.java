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
		int[] D = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(buff.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
			C[i] = Integer.parseInt(st.nextToken());
			D[i] = Integer.parseInt(st.nextToken());
		}
		
		// グラフの作成
		ArrayList<Edge>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Edge>();
		}
		for (int i = 1; i <= M; i++) {
			if (D[i] == 1) {
				G[A[i]].add(new Edge(B[i], 10000L * C[i] - 1L));
				G[B[i]].add(new Edge(A[i], 10000L * C[i] - 1L));
			}
			else {
				G[A[i]].add(new Edge(B[i], 10000L * C[i]));
				G[B[i]].add(new Edge(A[i], 10000L * C[i]));
			}
		}
		
		// ダイクストラ法（ダイクストラ法の詳しい説明については本書籍の 9.4 節、および ../chap09/answer_A64.java を参照）
		final long INF = (1L << 60);
		boolean[] kakutei = new boolean[N + 1];
		long[] cur = new long[N + 1];
		Arrays.fill(cur, INF);
		cur[1] = 0;
		Queue<State> Q = new PriorityQueue<>();
		Q.add(new State(cur[1], 1));
		while (Q.size() >= 1) {
			int pos = Q.remove().pos;
			if (kakutei[pos]) {
				continue;
			}
			kakutei[pos] = true;
			for (int i = 0; i < G[pos].size(); i++) {
				Edge e = G[pos].get(i);
				if (cur[e.to] > cur[pos] + e.cost) {
					cur[e.to] = cur[pos] + e.cost;
					Q.add(new State(cur[e.to], e.to));
				}
			}
		}
		
		// 答えを出力
		// マラソンコースの距離：cur[N]/10000 を小数点以下切り上げた値
		// コース上の木の数：cur[N] と distance*10000 の差分
		long distance = (cur[N] + 9999) / 10000;
		long numTrees = distance * 10000 - cur[N];
		System.out.println(distance + " " + numTrees);
	}

	// 重み付きグラフの辺のクラス Edge
	static class Edge {
		int to; long cost; // 行き先 to、長さ cost
		public Edge(int to, long cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	// ダイクストラ法の (cur[x], x) を管理するクラス（cur[x] = dist, x = pos に対応）
	static class State implements Comparable<State> {
		long dist; int pos;
		public State(long dist, int pos) {
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