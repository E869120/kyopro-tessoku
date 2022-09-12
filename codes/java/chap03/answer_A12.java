import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		N = sc.nextInt();
		K = sc.nextInt();
		A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 二分探索
		// Left は探索範囲の左端を、Right は探索範囲の右端を表す
		long Left = 1, Right = 1000000000;
		while (Left < Right) {
			long Mid = (Left + Right) / 2;
			boolean Answer = check(Mid);
			if (Answer == false) Left = Mid + 1; // 答えが Mid+1 以上であることが分かる
			if (Answer == true) Right = Mid; // 答えが Mid 以下であることが分かる
		}

		// 出力（このとき Left=Right になっている）
		System.out.println(Left);
	}

	static int N, K;
	static int[] A;

	// 答えが x 以下かを判定し、Yes であれば true、No であれば false を返す
	static boolean check(long x) {
		long sum = 0;
		for (int i = 1; i <= N; i++) sum += x / (long)A[i]; //「x ÷ A[i]」の小数点以下切り捨て
		if (sum >= (long)K) return true;
		return false;
	}
};
