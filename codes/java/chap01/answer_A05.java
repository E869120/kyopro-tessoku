import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int K = sc.nextInt();

		// 全探索
		int Answer = 0;
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				int z = K - x - y; // 白いカードに書かれるべき整数
				if (z >= 1 && z <= N) Answer += 1;
			}
		}

		// 出力
		System.out.println(Answer);
	}
};
