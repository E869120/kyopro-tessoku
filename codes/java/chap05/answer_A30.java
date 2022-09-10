import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		long n = sc.nextLong();
		long r = sc.nextLong();

		// 手順 1: 分子 a を求める
		long M = 1000000007;
		long a = 1;
		for (int i = 1; i <= n; i++) a = (a * i) % M;

		// 手順 2: 分母 b を求める
		long b = 1;
		for (int i = 1; i <= r; i++) b = (b * i) % M;
		for (int i = 1; i <= n - r; i++) b = (b * i) % M;

		// 手順 3: 答えを求める
		System.out.println(Division(a, b, M));
	}

	// a の b 乗を m で割った余りを返す関数
	static long Power(long a, long b, long m) {
		long p = a, Answer = 1;
		for (int i = 0; i < 30; i++) {
			int wari = (1 << i);
			if ((b / wari) % 2 == 1) {
				Answer = (Answer * p) % m;
			}
			p = (p * p) % m;
		}
		return Answer;
	}

	// a ÷ b を m で割った余りを返す関数
	static long Division(long a, long b, long m) {
		return (a * Power(b, m - 2, m)) % m;
	}
};
