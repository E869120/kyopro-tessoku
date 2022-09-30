import java.util.*;
 
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
 
		// 入力（前半部分）
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
 
		// 入力（後半部分）
		int D = sc.nextInt();
		int[] L = new int[D + 1];
		int[] R = new int[D + 1];
		for (int d = 1; d <= D; d++) {
			L[d] = sc.nextInt();
			R[d] = sc.nextInt();
		}
 
		// P[i] を求める
		int[] P = new int[N + 1];
		P[1] = A[1];
		for (int i = 2; i <= N; i++) P[i] = Math.max(P[i - 1], A[i]);
 
		// Q[i] を求める
		int[] Q = new int[N + 1];
		Q[N] = A[N];
		for (int i = N - 1; i >= 1; i--) Q[i] = Math.max(Q[i + 1], A[i]);
 
		// それぞれの日について答えを求める
		for (int d = 1; d <= D; d++) {
			System.out.println(Math.max(P[L[d]-1], Q[R[d]+1]));
		}
	}
};
