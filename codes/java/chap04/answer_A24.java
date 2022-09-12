import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 配列などの定義
		int LEN = 0; // LEN は L の長さ（例：L[4] まで書き込まれている場合 LEN=4）
		ArrayList<Integer> L = new ArrayList<Integer>();

		// 動的計画法（配列 dp を使わない実装）
		for (int i = 1; i <= N; i++) {
			int pos = ~Collections.binarySearch(L, A[i], (x, y) -> x.compareTo(y) >= 0 ? 1 : -1);

			// L の最大値より A[i] の方が大きかった場合
			if (pos >= LEN) {
				LEN += 1;
				L.add(A[i]);
			}
			// そうでない場合
			else {
				L.set(pos, A[i]);
			}
		}

		// 答えを出力
		System.out.println(LEN);
	}
};
