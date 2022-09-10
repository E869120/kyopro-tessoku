import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int L = sc.nextInt();
		int[] A = new int[N + 1];
		char[] B = new char[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.next().charAt(0);
		}

		// 答えを求める
		int Answer = 0;
		for (int i = 1; i <= N; i++) {
			if (B[i] == 'E') Answer = Math.max(Answer, L - A[i]);
			if (B[i] == 'W') Answer = Math.max(Answer, A[i]);
		}
		System.out.println(Answer);
	}
};
