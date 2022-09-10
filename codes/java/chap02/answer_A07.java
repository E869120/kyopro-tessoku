import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int D = sc.nextInt();
		int N = sc.nextInt();
		int[] B = new int[D + 2];
		int[] L = new int[N + 1];
		int[] R = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}

		// 前日比に加算
		for (int d = 1; d <= D; d++) B[d] = 0;
		for (int i = 1; i <= N; i++) {
			B[L[i]] += 1;
			B[R[i] + 1] -= 1;
		}

		// 累積和をとる → 出力
		int[] Answer = new int[D + 2];
		Answer[0] = 0;
		for (int d = 1; d <= D; d++) Answer[d] = Answer[d - 1] + B[d];
		for (int d = 1; d <= D; d++) System.out.println(Answer[d]);
	}
};
