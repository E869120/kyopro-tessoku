import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Point2D[] points = new Point2D[N + 1];
		for (int i = 1; i <= N; i++) {
			points[i] = new Point2D(sc.nextInt(), sc.nextInt());
		}

		// 山登り法
		int[] answer = hillClimbing(N, points);

		// 答えを出力
		for (int i = 1; i <= N + 1; i++) {
			System.out.println(answer[i]);
		}
	}

	// 合計距離を計算する関数
	static double getScore(int N, Point2D[] points, int[] P) {
		double score = 0.0;
		for (int i = 1; i <= N; i++) {
			score += points[P[i]].dist(points[P[i + 1]]);
		}
		return score;
	}

	// 山登り法によって答えを求める関数
	static int[] hillClimbing(int N, Point2D[] points) {
		// 初期解生成
		int[] P = new int[N + 2];
		for (int i = 1; i <= N; i++) {
			P[i] = i;
		}
		P[N + 1] = 1;
		
		// 山登り法
		final int NUM_LOOPS = 200000;
		Random rnd = new Random();
		double currentScore = getScore(N, points, P);
		for (int t = 1; t <= NUM_LOOPS; t++) {
			// ランダムに反転させる区間 [L, R] を選ぶ
			int L = 2 + rnd.nextInt(N - 1); // 2 以上 N 以下のランダムな整数
			int R = 2 + rnd.nextInt(N - 1); // 2 以上 N 以下のランダムな整数
			if (L > R) {
				// L と R を交換
				int z = L; L = R; R = z;
			}
			// P[L], P[L+1], ..., P[R] の順序を逆転させる
			for (int i = L, j = R; i < j; i++, j--) {
				// P[i] と P[j] を交換
				int z = P[i]; P[i] = P[j]; P[j] = z;
			}
			double newScore = getScore(N, points, P);
			// 改善すればスコアを更新、悪化すれば元に戻す
			if (currentScore >= newScore) {
				currentScore = newScore;
			}
			else {
				for (int i = L, j = R; i < j; i++, j--) {
					// P[i] と P[j] を交換
					int z = P[i]; P[i] = P[j]; P[j] = z;
				}
			}
		}

		return P;
	}

	// 二次元の点を扱うクラス Point2D
	static class Point2D {
		int x, y;
		public Point2D(int x, int y) {
			this.x = x;
			this.y = y;
		}
		// 2 点間の距離を求める関数
		double dist(Point2D p) {
			return Math.sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
		}
	}
}