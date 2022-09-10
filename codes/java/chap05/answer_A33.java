import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 全部 XOR した値（ニム和）を求める
		int XOR_Sum = A[1];
		for (int i = 2; i <= N; i++) XOR_Sum = (XOR_Sum ^ A[i]);

		// 出力
		if (XOR_Sum != 0) System.out.println("First");
		if (XOR_Sum == 0) System.out.println("Second");
	}
};
