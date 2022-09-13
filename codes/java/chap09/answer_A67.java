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

		// 辺の長さの小さい順にソートする
		// （書籍内のコードでは edgeList は (長さ, 辺番号) のペアになっていますが、ここでは辺番号のみを記録した配列を長さの小さい順にソートするという方法をとります）
		Integer[] edgeList = new Integer[M];
		for (int i = 0; i < M; i++) {
			edgeList[i] = i + 1;
		}
		Arrays.sort(
			edgeList,
			new Comparator<Integer>() {
				@Override
				public int compare(Integer id1, Integer id2) {
					return C[id1] - C[id2]; // C[id1] < C[id2] のとき id1 が id2 よりも前に来るようにする
				}
			}
		);
		
		// 最小全域木を求める
		int answer = 0;
		UnionFind uf = new UnionFind(N);
		for (int i = 0; i < M; i++) {
			int idx = edgeList[i];
			if (!uf.same(A[idx], B[idx])) {
				uf.unite(A[idx], B[idx]);
				answer += C[idx];
			}
		}

		// 答えの出力
		System.out.println(answer);
	}
	
	// Union-Find 木を実装したクラス UnionFind
	static class UnionFind {
		int n;
		int[] par;
		int[] size;

		// n 頂点の Union-Find を作成
		public UnionFind(int n) {
			this.n = n;
			par = new int[n + 1];
			size = new int[n + 1];
			Arrays.fill(par, -1); // 最初は親が無い (par[i] = -1)
			Arrays.fill(size, 1); // 最初はグループの頂点数が 1 (size[i] = 1)
		}

		// 頂点 x の根を返す関数
		int root(int x) {
			while (true) {
				if (par[x] == -1) {
					break;  // 1 個先（親）がなければ、ここが根
				}
				x = par[x]; // 1 個先（親）に進む
			}
			return x;
		}

		// 要素 u と v を統合する関数
		void unite(int u, int v) {
			int rootU = root(u);
			int rootV = root(v);
			if (rootU == rootV) {
				return; // u と v が同グループのときは処理を行わない
			}
			if (size[rootU] < size[rootV]) {
				par[rootU] = rootV;
				size[rootV] += size[rootU];
			}
			else {
				par[rootV] = rootU;
				size[rootU] += size[rootV];
			}
		}

		// 要素 u と v が同一のグループかどうかを返す関数
		boolean same(int u, int v) {
			return root(u) == root(v);
		}
	}
}