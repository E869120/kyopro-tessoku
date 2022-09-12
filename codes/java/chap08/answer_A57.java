import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		int[] A = new int[N + 1];
		int[] X = new int[Q + 1];
		int[] Y = new int[Q + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		for (int i = 1; i <= Q; i++) {
			X[i] = sc.nextInt();
			Y[i] = sc.nextInt();
		}

		// 前計算
		final int LEVELS = 30;
		int[][] dp = new int[LEVELS][N + 1];
		for (int i = 1; i <= N; i++) {
			dp[0][i] = A[i];
		}
		for (int d = 1; d <= 29; d++) {
			for (int i = 1; i <= N; i++) {
				dp[d][i] = dp[d - 1][dp[d - 1][i]];
			}
		}

		// クエリの処理
		for (int i = 1; i <= Q; i++) {
			int currentPlace = X[i];
			for (int d = 29; d >= 0; d--) {
				if ((Y[i] / (1 << d)) % 2 == 1) {
					currentPlace = dp[d][currentPlace];
				}
			}
			System.out.println(currentPlace);
		}
	}
}