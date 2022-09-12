import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int Q = sc.nextInt();
		int[] queryType = new int[Q + 1];
		int[] x = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			queryType[i] = sc.nextInt();
			if (queryType[i] == 1) {
				x[i] = sc.nextInt();
			}
		}

		// クエリの処理
		Queue<Integer> T = new PriorityQueue<>();
		for (int i = 1; i <= Q; i++) {
			if (queryType[i] == 1) {
				T.add(x[i]);
			}
			if (queryType[i] == 2) {
				System.out.println(T.peek());
			}
			if (queryType[i] == 3) {
				T.remove();
			}
		}
	}
}