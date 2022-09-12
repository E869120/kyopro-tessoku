import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力（文字列は 0 文字目から始まることに注意！）
		String S = sc.next(); int N = S.length();
		String T = sc.next(); int M = T.length();

		// 配列 dp の定義
		int[][] dp = new int[N + 1][M + 1];

		// 動的計画法
		dp[0][0] = 0;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= M; j++) {
				if (i >= 1 && j >= 1 && S.charAt(i-1) == T.charAt(j-1)) {
					dp[i][j] = Math.max(dp[i - 1][j], Math.max(dp[i][j - 1], dp[i - 1][j - 1] + 1));
				}
				else if (i >= 1 && j >= 1) {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
				}
				else if (i >= 1) {
					dp[i][j] = dp[i - 1][j];
				}
				else if (j >= 1) {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}

		// 出力
		System.out.println(dp[N][M]);
	}
};
