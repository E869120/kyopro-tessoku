import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		for (int i = 2; i <= N; i++) A[i] = sc.nextInt();
		for (int i = 3; i <= N; i++) B[i] = sc.nextInt();

		// 動的計画法
		int[] dp = new int[N + 1];
		dp[1] = 0;
		dp[2] = A[2];
		for (int i = 3; i <= N; i++) {
			dp[i] = Math.min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
		}

		// 答えの復元
		// 変数 Place は現在位置（ゴールから進んでいく）
		// たとえば入力例の場合、Place は 5 → 4 → 2 → 1 と変化していく
		ArrayList<Integer> Answer = new ArrayList<Integer>();
		int Place = N;
		while (true) {
			Answer.add(Place);
			if (Place == 1) break;

			// どこから部屋 Place に向かうのが最適かを求める
			if (dp[Place - 1] + A[Place] == dp[Place]) Place = Place - 1;
			else Place = Place - 2;
		}

		// 出力
		System.out.println(Answer.size());
		for (int i = Answer.size() - 1; i >= 0; i--) {
			if (i < Answer.size() - 1) System.out.print(" ");
			System.out.print(Answer.get(i));
		}
		System.out.println();
	}
};
