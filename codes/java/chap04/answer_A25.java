import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力（配列 c は 0 番目から始まることに注意！）
		int H = sc.nextInt();
		int W = sc.nextInt();
		String[] c = new String[H];
		for (int i = 0; i < H; i++) c[i] = sc.next();

		// 動的計画法
		long[][] dp = new long[H][W];
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i == 0 && j == 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = 0;
					if (i >= 1 && c[i - 1].charAt(j) == '.') dp[i][j] += dp[i - 1][j];
					if (j >= 1 && c[i].charAt(j - 1) == '.') dp[i][j] += dp[i][j - 1];
				}
			}
		}

		// 出力
		System.out.println(dp[H-1][W-1]);
	}
};
