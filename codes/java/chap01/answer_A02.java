import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int X = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 全探索（変数 Answer は「既に x が見つかったかどうか」を表す）
		boolean Answer = false;
		for (int i = 1; i <= N; i++) {
			if (A[i] == X) Answer = true;
		}

		// 出力
		if (Answer == true) System.out.println("Yes");
		else System.out.println("No");
	}
};
