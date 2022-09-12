import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// 配列 T の作成・重複を消す
		HashSet<Integer> tmp = new HashSet<Integer>();
		for (int i = 1; i <= N; i++) tmp.add(A[i]);
		ArrayList<Integer> T = new ArrayList<>(tmp);
		Collections.sort(T);

		// 答えを求める
		int[] B = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			B[i] = ~Collections.binarySearch(T, A[i], (x, y) -> x.compareTo(y) >= 0 ? 1 : -1);
			B[i] += 1;
		}

		// 答えを空白区切りで出力
		for (int i = 1; i <= N; i++) {
			if (i >= 2) System.out.print(" ");
			System.out.print(B[i]);
		}
		System.out.println();
	}
};
