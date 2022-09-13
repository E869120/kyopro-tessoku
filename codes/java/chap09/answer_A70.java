import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = new int[N + 1];
		int[] X = new int[M + 1];
		int[] Y = new int[M + 1];
		int[] Z = new int[M + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		for (int i = 1; i <= M; i++) {
			X[i] = sc.nextInt();
			Y[i] = sc.nextInt();
			Z[i] = sc.nextInt();
		}

		// 隣接リストを作成し、グラフに辺を追加
		ArrayList<Integer>[] G = new ArrayList[1 << N];
		for (int i = 0; i < (1 << N); i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < (1 << N); i++) {
			for (int j = 1; j <= M; j++) {
				int nextState = getNext(N, i, X[j], Y[j], Z[j]);
				G[i].add(nextState);
			}
		}

		// スタート・ゴールの頂点番号を求める
		int start = 0;
		for (int i = 1; i <= N; i++) {
			if (A[i] == 1) {
				start += (1 << (i - 1));
			}
		}
		int goal = (1 << N) - 1;

		// 配列の初期化／スタート地点をキューに入れる
		int[] dist = new int[1 << N];
		Arrays.fill(dist, -1);
		dist[start] = 0;
		Queue<Integer> Q = new LinkedList<>();
		Q.add(start);

		// 幅優先探索
		while (Q.size() >= 1) {
			int pos = Q.remove();
			for (int i = 0; i < G[pos].size(); i++) {
				int nex = G[pos].get(i);
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex);
				}
			}
		}

		// 答えを出力
		System.out.println(dist[goal]);
	}
	
	// 頂点 pos の状態から「ランプ x, y, z の状態」を反転させたときの頂点番号を返す関数
	// （書籍内のコードでは「頂点 pos の状態から idx 種類目の操作を行ったとき」の頂点番号を返す関数を実装しているが、これとは少し異なる実装をしていることに注意）
	static int getNext(int N, int pos, int x, int y, int z) {
		// pos の 2 進法表記を使って、頂点 pos が表すランプの状態 state を計算
		// （2 進法に変換する方法は 1.4 節を参照）
		int[] state = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			int wari = (1 << (i - 1));
			state[i] = (pos / wari) % 2;
		}

		// ランプ x, y, z の状態を反転
		state[x] = 1 - state[x];
		state[y] = 1 - state[y];
		state[z] = 1 - state[z];

		// 10 進法に変換する方法も 1.4 節を参照
		int ret = 0;
		for (int i = 1; i <= N; i++) {
			if (state[i] == 1) {
				ret += (1 << (i - 1));
			}
		}
		return ret;
	}
}

// 注意 1：この問題に対してはより簡潔な実装もありますので、もしよければ answer_A70_extra.py もご覧ください。