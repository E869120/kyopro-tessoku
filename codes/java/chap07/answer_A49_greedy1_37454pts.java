// ###############################################
// # 本の 266 ページ前半の貪欲法を用いた実装です
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
		int CurrentScore = 0;
		for (int i = 1; i <= T; i++) {
			// パターン A の場合のスコアを求める
			int ScoreA = CurrentScore;
			for (int j = 1; j <= 20; j++) PatA[j] = A[j];
			PatA[P[i]] += 1;
			PatA[Q[i]] += 1;
			PatA[R[i]] += 1;
			for (int j = 1; j <= 20; j++) {
				if (PatA[j] == 0) ScoreA += 1;
			}
 
			// パターン B の場合のスコアを求める
			int ScoreB = CurrentScore;
			for (int j = 1; j <= 20; j++) PatB[j] = A[j];
			PatB[P[i]] -= 1;
			PatB[Q[i]] -= 1;
			PatB[R[i]] -= 1;
			for (int j = 1; j <= 20; j++) {
				if (PatB[j] == 0) ScoreB += 1;
			}
 
			// スコアの大きい方を採用
			if (ScoreA >= ScoreB) {
				System.out.println("A");
				CurrentScore = ScoreA;
				for (int j = 1; j <= 20; j++) A[j] = PatA[j];
			}
			else {
				System.out.println("B");
				CurrentScore = ScoreB;
				for (int j = 1; j <= 20; j++) A[j] = PatB[j];
			}
		}
	}
};
