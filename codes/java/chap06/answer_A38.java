import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int D = sc.nextInt();
		int N = sc.nextInt();
		int[] L = new int[N + 1];
		int[] R = new int[N + 1];
		int[] H = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
			H[i] = sc.nextInt();
		}

		// 配列の初期化（1 日は 24 時間）
		int[] LIM = new int[D + 1];
		for (int i = 1; i <= D; i++) LIM[i] = 24;

		// 上限値を求める
		for (int i = 1; i <= N; i++) {
			for (int j = L[i]; j <= R[i]; j++) LIM[j] = Math.min(LIM[j], H[i]);
	  }

		// 出力
		int Answer = 0;
		for (int i = 1; i <= D; i++) Answer += LIM[i];
		System.out.println(Answer);
	}
};
