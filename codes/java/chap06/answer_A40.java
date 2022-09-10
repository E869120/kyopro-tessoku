import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 個数を数える
		long[] cnt = new long[101];
		for (int i = 1; i <= 100; i++) cnt[i] = 0;
		for (int i = 1; i <= N; i++) cnt[A[i]] += 1;

		// 答えを求める
		// nC3 = n * (n-1) * (n-2) / 6 を使っている
		long Answer = 0;
		for (int i = 1; i <= 100; i++) {
			Answer += cnt[i] * (cnt[i]-1) * (cnt[i]-2) / 6;
		}
		System.out.println(Answer);
	}
};
