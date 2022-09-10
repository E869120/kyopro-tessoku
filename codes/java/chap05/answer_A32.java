import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();

		// 勝者を計算する
		boolean[] dp = new boolean[N + 1];
		for (int i = 0; i <= N; i++) {
			if (i >= A && dp[i-A] == false) dp[i] = true; // 勝ちの状態
			else if (i >= B && dp[i-B] == false) dp[i] = true; // 勝ちの状態
			else dp[i] = false; // 負けの状態
		}

		// 出力
		if (dp[N] == true) System.out.println("First");
		else System.out.println("Second");
	}
};
