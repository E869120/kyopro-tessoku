import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 配列 R の定義
		int[] R = new int[N + 1];

		// しゃくとり法
		for (int i = 1; i <= N - 1; i++) {
			// スタート地点を決める
			if (i == 1) R[i] = 1;
			else R[i] = R[i - 1];

			// ギリギリまで増やしていく
			while (R[i] < N && A[R[i] + 1] - A[i] <= K) {
				R[i] += 1;
			}
		}

		// 出力（答えは最大 50 億程度になるので long 型を使う必要があります）
		long Answer = 0;
		for (int i = 1; i <= N - 1; i++) Answer += (R[i] - i);
		System.out.println(Answer);
	}
};
