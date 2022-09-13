import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] P = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				P[i][j] = sc.nextInt();
			}
		}

		// 「転倒数を求める問題」2 つに分解する
		int[] X = new int[N + 1];
		int[] Y = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (P[i][j] != 0) {
					X[i] = P[i][j];
					Y[j] = P[i][j];
				}
			}
		}

		// X の転倒数・Y の転倒数を求める
		int inversionX = 0;
		int inversionY = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (X[i] > X[j]) {
					inversionX += 1;
				}
				if (Y[i] > Y[j]) {
					inversionY += 1;
				}
			}
		}

		// 出力
		System.out.println(inversionX + inversionY);
	}
}