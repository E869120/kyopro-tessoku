import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		N = sc.nextInt();
		X = sc.nextInt();
		A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 二分探索を行う
		int Answer = search(X);
		System.out.println(Answer);
	}

	static int N, X;
	static int[] A;
	
	// 整数 x が何番目に存在するかを返す
	static int search(int x) {
		int L = 1, R = N;
		while (L <= R) { // 探索範囲がなくなるまで、比較を続ける
			int M = (L + R) / 2;
			if (x < A[M]) R = M - 1;
			if (x == A[M]) return M;
			if (x > A[M]) L = M + 1;
		}
		return -1; // 整数 x が存在しない（注：この問題の制約で -1 が返されることはない）
	}
};
