import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int A = sc.nextInt();
		int B = sc.nextInt();

		// 出力
		System.out.println(GCD(A, B));
	}

	// 正の整数 A と B の最大公約数を返す関数
	// GCD は Greatest Common Divisor（最大公約数）の略
	static int GCD(int A, int B) {
		while (A >= 1 && B >= 1) {
			if (A >= B) {
				A %= B; // A の値を変更する場合
			}
			else {
				B %= A; // B の値を変更する場合
			}
		}
		if (A >= 1) {
			return A;
		}
		return B;
	}
};
