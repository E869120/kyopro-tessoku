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
			x[i] = sc.nextInt();
		}

		// クエリの処理
		TreeSet<Integer> S = new TreeSet<>();
		for (int i = 1; i <= Q; i++) {
			if (queryType[i] == 1) {
				S.add(x[i]);
			}
			if (queryType[i] == 2) {
				S.remove(x[i]);
			}
			if (queryType[i] == 3) {
				Integer res = S.higher(x[i] - 1); // higher 関数は「引数より大きいもののうち最小の要素」を返すので、引数を x[i] - 1 にする
				System.out.println(res != null ? res : -1);
			}
		}
	}
}