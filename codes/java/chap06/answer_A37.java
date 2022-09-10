import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int M = sc.nextInt();
		long B = sc.nextLong();
		long[] A = new long[N + 1];
		long[] C = new long[M + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextLong();
		for (int j = 1; j <= M; j++) C[j] = sc.nextLong();

		// 答えの計算
		long Answer = 0;
		for (int i = 1; i <= N; i++) Answer += A[i] * M;
		Answer += B * N * M;
		for (int j = 1; j <= M; j++) Answer += C[j] * N;

		// 出力
		System.out.println(Answer);
	}
};
