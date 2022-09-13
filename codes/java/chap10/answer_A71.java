import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力（書籍とは異なり A[i], B[i] は 0-indexed で入力しています）
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Integer[] A = new Integer[N];
		Integer[] B = new Integer[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		for (int i = 0; i < N; i++) {
			B[i] = sc.nextInt();
		}

		// 配列のソート
		Arrays.sort(A);
		Arrays.sort(B, Collections.reverseOrder());

		// 答えを求めて出力
		int answer = 0;
		for (int i = 0; i < N; i++) {
			answer += A[i] * B[i];
		}
		System.out.println(answer);
	}
}