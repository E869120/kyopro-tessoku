import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int W = sc.nextInt();
		int[] w = new int[N + 1];
		int[] v = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			w[i] = sc.nextInt();
			v[i] = sc.nextInt();
		}

		// 配列 dp の定義・初期化
		long[][] dp = new long[N + 1][W + 1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= W; j++) dp[i][j] = -1000000000000L;
		}

		// 動的計画法
		dp[0][0] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= W; j++) {
				if (j < w[i]) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}

		// 出力
		long Answer = 0;
		for (int i = 0; i <= W; i++) Answer = Math.max(Answer, dp[N][i]);
		System.out.println(Answer);
	}
};
