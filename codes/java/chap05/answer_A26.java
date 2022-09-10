import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int Q = sc.nextInt();
		int[] X = new int[Q + 1];
		for (int i = 1; i <= Q; i++) X[i] = sc.nextInt();

		// 出力
		for (int i = 1; i <= Q; i++) {
			boolean Answer = isPrime(X[i]);
			if (Answer == true) System.out.println("Yes");
			if (Answer == false) System.out.println("No");
		}
	}

	// x が素数のとき true を、素数ではないとき false を返す関数
	static boolean isPrime(int x) {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) return false;
		}
		return true;
	}
};
