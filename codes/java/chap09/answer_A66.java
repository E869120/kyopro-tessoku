import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 入力（高速な入出力のため、Scanner の代わりに BufferedReader を使っています）
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		int[] query = new int[Q + 1];
		int[] u = new int[Q + 1];
		int[] v = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			st = new StringTokenizer(buff.readLine());
			query[i] = Integer.parseInt(st.nextToken());
			u[i] = Integer.parseInt(st.nextToken());
			v[i] = Integer.parseInt(st.nextToken());
		}
		
		// クエリの処理
		// （高速な出力のため、System.out.println ではなく PrintWriter を使っています）
		PrintWriter output = new PrintWriter(System.out);
		UnionFind uf = new UnionFind(N);
		for (int i = 1; i <= Q; i++) {
			if (query[i] == 1) {
				uf.unite(u[i], v[i]);
			}
			if (query[i] == 2) {
				if (uf.same(u[i], v[i])) {
					output.println("Yes");
				}
				else {
					output.println("No");
				}
			}
		}
		output.flush();
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