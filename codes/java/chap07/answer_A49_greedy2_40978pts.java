// ###############################################
// # 本の 272 ページ後半の評価関数を用いた実装です
// ###############################################

import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = 20;
		int T = sc.nextInt();
		int[] P = new int[T + 1];
		int[] Q = new int[T + 1];
		int[] R = new int[T + 1];
		for (int i = 1; i <= T; i++) {
			P[i] = sc.nextInt();
			Q[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}

		// 配列 A の初期化
		int[] A = new int[21];
		int[] PatA = new int[21];
		int[] PatB = new int[21];
		for (int i = 1; i <= 20; i++) A[i] = 0;

		// 貪欲法
		for (int i = 1; i <= T; i++) {
			// パターン A の場合のスコアを求める
			int ScoreA = 0;
			for (int j = 1; j <= 20; j++) PatA[j] = A[j];
			PatA[P[i]] += 1;
			PatA[Q[i]] += 1;
			PatA[R[i]] += 1;
			for (int j = 1; j <= 20; j++) ScoreA += Math.abs(PatA[j]);

			// パターン B の場合のスコアを求める
			int ScoreB = 0;
			for (int j = 1; j <= 20; j++) PatB[j] = A[j];
			PatB[P[i]] -= 1;
			PatB[Q[i]] -= 1;
			PatB[R[i]] -= 1;
			for (int j = 1; j <= 20; j++) ScoreB += Math.abs(PatB[j]);

			// スコアの小さい方を採用
			if (ScoreA <= ScoreB) {
				System.out.println("A");
				for (int j = 1; j <= 20; j++) A[j] = PatA[j];
			}
			else {
				System.out.println("B");
				for (int j = 1; j <= 20; j++) A[j] = PatB[j];
			}
		}
	}
};
