import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		char[] T = new char[N + 1];
		long[] A = new long[N + 1];
		for (int i = 1; i <= N; i++) {
			T[i] = sc.next().charAt(0);
			A[i] = sc.nextInt();
		}

		// 出力（Answer は現在の黒板の数）
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			if (T[i] == '+') Answer += A[i];
			if (T[i] == '-') Answer -= A[i];
			if (T[i] == '*') Answer *= A[i];

			// 引き算で答えが 0 未満になった場合
			if (Answer < 0) Answer += 10000;

			// ここで余りをとっている！
			Answer %= 10000;
			System.out.println(Answer);
		}
	}
};
