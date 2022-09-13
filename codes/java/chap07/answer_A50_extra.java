// 本プログラムは、書籍 p.283「さらなる高みへ」を実装した、焼きなまし法のコードとなります。
// ベースとなる山登り法の実装については、answer_A50.java をご覧ください。
// ※ 期待されるスコアは、およそ 99.977 億点です。

import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		final int N = 100;
		final int Q = 1000;
		int[][] A = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j] = sc.nextInt();
			}
		}

		// 初期解を生成
		Random rnd = new Random();
		Answer ans = new Answer(N, Q, A, rnd);

		// 山登り法：変数の設定（5.4 秒ループを回す）
		final double TIME_LIMIT = 5.4;
		long ti = System.currentTimeMillis();
		int currentScore = ans.getScore();

		// 山登り法スタート
		int loops = 0;
		while ((System.currentTimeMillis() - ti) / 1000.0 < TIME_LIMIT) {
			// 「小さな変更」をランダムに選ぶ
			int t = rnd.nextInt(Q);
			int h_limit = 14;
			if (currentScore >= 199900000) {
				h_limit = 1;
			}
			else if (currentScore >= 199500000) {
				h_limit = 7;
			}
			int old_x = ans.X[t], new_x = ans.X[t] + (rnd.nextInt(3) - 1);  // X[t] を -1 から +1 まで増減
			int old_y = ans.Y[t], new_y = ans.Y[t] + (rnd.nextInt(3) - 1);  // Y[t] を -1 から +1 まで増減
			int old_z = ans.H[t], new_z = ans.H[t] + (rnd.nextInt(h_limit * 2 + 1) - h_limit); // H[t] を -h_limit から +h_limit まで増減
			if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N || new_z <= 0 || new_z > N) {
				continue;
			}
			// とりあえず変更し、スコアを評価する
			ans.change(t, new_x, new_y, new_z);
			int newScore = ans.getScore();
			// スコアに応じて採用／不採用を決める
			double temperature = 180.0 - 179.0 * ((System.currentTimeMillis() - ti) / 1000.0 / TIME_LIMIT);
			double probability = Math.exp(Math.min((newScore - currentScore) / temperature, 0.0));
			if (rnd.nextDouble() < probability) {
				currentScore = newScore;
			}
			else {
				ans.change(t, old_x, old_y, old_z);
			}
			loops += 1;
		}

		// 出力
		System.out.println(Q);
		for (int i = 0; i < Q; i++) {
			System.out.println(ans.X[i] + " " + ans.Y[i] + " " + ans.H[i]);
		}
		System.err.println("loops = " + loops);
		System.err.println("score = " + currentScore);
	}

	// 操作手順や盤面を記録した構造体 Answer
	// （ここでは書籍内のコードとは異なり、操作の番号は 1-indexed ではなく 0-indexed で実装しています（つまり番号が 0 から 999 になります））
	static class Answer {
		int N; // 盤面のサイズ
		int Q; // 操作の回数
		int[] X;
		int[] Y;
		int[] H;
		int[][] A;
		int[][] B;
		// 初期解を生成
		public Answer(int N, int Q, int[][] A, Random rnd) {
			this.N = N;
			this.Q = Q;
			this.A = new int[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					this.A[i][j] = A[i][j];
				}
			}
			X = new int[Q];
			Y = new int[Q];
			H = new int[Q];
			B = new int[N][N];
			for (int i = 0; i < Q; i++) {
				X[i] = rnd.nextInt(N); // 0 以上 N-1 以下のランダムな整数
				Y[i] = rnd.nextInt(N); // 0 以上 N-1 以下のランダムな整数
				H[i] = 1;
				B[Y[i]][X[i]] += 1;
			}
		}
		// X[t] = x, Y[t] = y, H[t] = h に変更する関数
		void change(int t, int x, int y, int h) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					B[i][j] -= Math.max(H[t] - Math.abs(Y[t] - i) - Math.abs(X[t] - j), 0);
				}
			}
			X[t] = x;
			Y[t] = y;
			H[t] = h;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					B[i][j] += Math.max(H[t] - Math.abs(Y[t] - i) - Math.abs(X[t] - j), 0);
				}
			}
		}
		// 現在のスコアを返す関数
		int getScore() {
			int sum = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					sum += Math.abs(A[i][j] - B[i][j]);
				}
			}
			return 200000000 - sum;
		}
	}
}