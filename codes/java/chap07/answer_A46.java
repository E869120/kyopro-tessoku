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

		// 貪欲法
		int[] answer = playGreedy(N, points);

		// 答えを出力
		for (int i = 1; i <= N + 1; i++) {
			System.out.println(answer[i]);
		}
	}

	// 貪欲法によって答えを求める関数
	static int[] playGreedy(int N, Point2D[] points) {
		// 配列の初期化
		int currentPlace = 1;
		int[] P = new int[N + 2];
		boolean[] visited = new boolean[N + 1]; // Java では new で初期化した配列の要素は false になることに注意
		P[1] = 1;
		visited[1] = true;

		// 貪欲法スタート
		for (int i = 2; i <= N; i++) {
			double minDist = 1.0e+99; // 現時点での距離の最小
			int minID = -1;           // 次はどの都市に移動すればよいか
			// 距離が最小となる都市を探す
			for (int j = 1; j <= N; j++) {
				if (visited[j]) {
					continue;
				}
				double newDist = points[currentPlace].dist(points[j]);
				if (minDist > newDist) {
					minDist = newDist;
					minID = j;
				}
			}

			// 現在位置の更新
			visited[minID] = true;
			P[i] = minID;
			currentPlace = minID;
		}

		// 最後に訪問する都市
		P[N + 1] = 1;

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