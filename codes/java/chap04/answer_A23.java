import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[][] A = new int[M + 1][N + 1];
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) A[i][j] = sc.nextInt();
		}

		// 配列の初期化
		int[][] dp = new int[M + 1][1 << N];
		for (int i = 0; i <= M; i++) {
			for (int j = 0; j < (1 << N); j++) dp[i][j] = 1000000000;
		}

		// 動的計画法
		dp[0][0] = 0;
		for (int i = 1; i <= M; i++) {
			for (int j = 0; j < (1 << N); j++) {
				// already[k] = 1 のとき、品物 k は既に無料になっている
				int[] already = new int[N + 1];
				for (int k = 1; k <= N; k++) {
					if ((j / (1 << (k - 1)) % 2) == 0) already[k] = 0;
					else already[k] = 1;
				}

				// クーポン券 i を選んだ場合の整数表現 v を計算する
				int v = 0;
				for (int k = 1; k <= N; k++) {
					if (already[k] == 1 || A[i][k] == 1) v += (1 << (k - 1));
				}

				// 遷移を行う
				dp[i][j] = Math.min(dp[i][j], dp[i - 1][j]);
				dp[i][v] = Math.min(dp[i][v], dp[i - 1][j] + 1);
			}
		}

		// 出力（すべて選んだ場合の整数表現は 2^N-1）
		if (dp[M][(1 << N) - 1] == 1000000000) System.out.println("-1");
		else System.out.println(dp[M][(1 << N) - 1]);
	}
};
