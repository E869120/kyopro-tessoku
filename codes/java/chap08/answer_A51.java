import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int Q = sc.nextInt();
		int[] queryType = new int[Q + 1];
		String[] x = new String[Q + 1];
		for (int i = 1; i <= Q; i++) {
			queryType[i] = sc.nextInt();
			if (queryType[i] == 1) {
				x[i] = sc.next();
			}
		}

		// クエリの処理
		Stack<String> S = new Stack<>();
		for (int i = 1; i <= Q; i++) {
			if (queryType[i] == 1) {
				S.push(x[i]);
			}
			if (queryType[i] == 2) {
				System.out.println(S.peek());
			}
			if (queryType[i] == 3) {
				S.pop();
			}
		}
	}
}