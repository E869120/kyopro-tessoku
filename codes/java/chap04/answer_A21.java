import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int[] P = new int[N + 1];
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			P[i] = sc.nextInt();
			A[i] = sc.nextInt();
		}

		// 動的計画法（LEN は r-l の値）
		int[][] dp = new int[N + 1][N + 1];
		dp[1][N] = 0;
		for (int LEN = N - 2; LEN >= 0; LEN--) {
			for (int l = 1; l <= N - LEN; l++) {
				int r = l + LEN;

				// score1 の値（l-1 番目のブロックを取り除くときの得点）を求める
				int score1 = 0;
				if (l >= 2 && l <= P[l - 1] && P[l - 1] <= r) score1 = A[l - 1];

				// score2 の値（r+1 番目のブロックを取り除くときの得点）を求める
				int score2 = 0;
				if (r < N && l <= P[r + 1] && P[r + 1] <= r) score2 = A[r + 1];

				// dp[l][r] を求める
				if (l == 1) {
					dp[l][r] = dp[l][r + 1] + score2;
				}
				else if (r == N) {
					dp[l][r] = dp[l - 1][r] + score1;
				}
				else {
					dp[l][r] = Math.max(dp[l - 1][r] + score1, dp[l][r + 1] + score2);
				}
			}
		}

		// 出力
		int Answer = 0;
		for (int i = 1; i <= N; i++) Answer = Math.max(Answer, dp[i][i]);
		System.out.println(Answer);
	}
};
