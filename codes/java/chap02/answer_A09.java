import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int H = sc.nextInt();
		int W = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		int[] C = new int[N + 1];
		int[] D = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
			C[i] = sc.nextInt();
			D[i] = sc.nextInt();
		}

		// 各日について加算
		int[][] X = new int[H + 2][W + 2];
		int[][] Z = new int[H + 2][W + 2];
		for (int t = 1; t <= N; t++) {
			X[A[t]][B[t]] += 1;
			X[A[t]][D[t]+1] -= 1;
			X[C[t]+1][B[t]] -= 1;
			X[C[t]+1][D[t]+1] += 1;
		}

		// 二次元累積和を求める
		for (int i = 0; i <= H; i++) {
			for (int j = 0; j <= W; j++) Z[i][j] = 0;
		}
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) Z[i][j] = Z[i][j - 1] + X[i][j];
		}
		for (int j = 1; j <= W; j++) {
			for (int i = 1; i <= H; i++) Z[i][j] = Z[i - 1][j] + Z[i][j];
		}

		// 出力
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (j >= 2) System.out.print(" ");
				System.out.print(Z[i][j]);
			}
			System.out.println();
		}
	}
};
