import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力（前半部分）
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] X = new int[H + 2][W + 2];
		int[][] Z = new int[H + 2][W + 2];
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) X[i][j] = sc.nextInt();
		}

		// 入力（後半部分）
		int Q = sc.nextInt();
		int[] A = new int[Q + 1];
		int[] B = new int[Q + 1];
		int[] C = new int[Q + 1];
		int[] D = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
			C[i] = sc.nextInt();
			D[i] = sc.nextInt();
		}

		// 配列 Z の初期化
		for (int i = 0; i <= H; i++) {
			for (int j = 0; j <= W; j++) Z[i][j] = 0;
		}

		// 横方向に累積和をとる
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) Z[i][j] = Z[i][j - 1] + X[i][j];
		}

		// 縦方向に累積和をとる
	  for (int j = 1; j <= W; j++) {
			for (int i = 1; i <= H; i++) Z[i][j] = Z[i - 1][j] + Z[i][j];
		}

		// 答えを求める
		for (int i = 1; i <= Q; i++) {
			System.out.println(Z[C[i]][D[i]] + Z[A[i]-1][B[i]-1] - Z[A[i]-1][D[i]] - Z[C[i]][B[i]-1]);
		}
	}
};
