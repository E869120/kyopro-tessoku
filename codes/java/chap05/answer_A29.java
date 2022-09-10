import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		long a = sc.nextLong();
		long b = sc.nextLong();

		// 出力（Answer は現在の黒板の数）
		System.out.println(Power(a, b, 1000000007));
	}

	// a の b 乗を m で割った余りを返す関数
	// 変数 a は a^1 → a^2 → a^4 → a^8 → a^16 → ･･･ と変化
	static long Power(long a, long b, long m) {
		long p = a, Answer = 1;
		for (int i = 0; i < 30; i++) {
			int wari = (1 << i);
			if ((b / wari) % 2 == 1) {
				Answer = (Answer * p) % m; // 「a の 2i 乗」が掛けられるとき
			}
			p = (p * p) % m;
		}
		return Answer;
	}
};
