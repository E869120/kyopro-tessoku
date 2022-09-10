import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int Q = sc.nextInt();

		// 配列の初期化
		int State = 1;
		int[] E = new int[N + 1];
		for (int i = 1; i <= N; i++) E[i] = i;

		// クエリの処理
		for (int i = 1; i <= Q; i++) {
			int Type, x, y;
			Type = sc.nextInt();

			// [1] 変更操作
			if (Type == 1) {
				x = sc.nextInt();
				y = sc.nextInt();
				if (State == 1) E[x] = y;
				if (State == 2) E[N+1-x] = y;
			}

			// [2] 反転操作
			if (Type == 2) {
				if (State == 1) State = 2;
				else State = 1;
			}

			// [3] 取得操作
			if (Type == 3) {
				x = sc.nextInt();
				if (State == 1) System.out.println(E[x]);
				if (State == 2) System.out.println(E[N + 1 - x]);
			}
		}
	}
};
