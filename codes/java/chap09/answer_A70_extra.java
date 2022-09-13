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
		// （ここではグラフを実際に持たずに、pos から出る辺をそのまま計算して幅優先探索を行います）
		while (Q.size() >= 1) {
			int pos = Q.remove();
			for (int i = 1; i <= M; i++) {
				// ビット演算の XOR を使って、操作後の頂点番号を求めます（XOR についてはコラム 1 を参照）。
				// ランプ k を反転することは、頂点番号の 2^k の位を反転すること、すなわち 2^k を XOR することと同じになります。
				int nex = pos ^ (1 << (X[i] - 1)) ^ (1 << (Y[i] - 1)) ^ (1 << (Z[i] - 1));
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex);
				}
			}
		}

		// 答えを出力
		System.out.println(dist[goal]);
	}
}

// 注意 1：このプログラムは answer_A70.java と比較してコードが簡潔であるだけでなく、実行速度の面でも優れています。
//         なぜなら、隣接リストを実際に作るのを省けたり、配列 state を作らずに 6 回のビット演算だけで「次の頂点番号」が求められたりするからです。
//         なお、ビット演算は、掛け算 (*) や割り算 (/) などの演算と比べて大幅に高速です。
