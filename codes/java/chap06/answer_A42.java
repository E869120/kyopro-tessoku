import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
		}

		// (a, b) の組を全探索
		int Answer = 0;
		for (int a = 1; a <= 100; a++) {
			for (int b = 1; b <= 100; b++) {
				int Score = GetScore(a, b, N, K, A, B);
				Answer = Math.max(Answer, Score);
			}
		}

		// 出力
		System.out.println(Answer);
	}

	// 整数の組 (a, b) が決まったときの、参加可能な生徒数を返す関数
	static int GetScore(int a, int b, int N, int K, int[] A, int[] B) {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (a<=A[i] && A[i]<=a+K && b<=B[i] && B[i]<=b+K) {
				cnt += 1;
			}
		}
		return cnt;
	}
};
