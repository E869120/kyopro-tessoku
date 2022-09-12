import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		String S = sc.next();
		int[] a = new int[Q + 1];
		int[] b = new int[Q + 1];
		int[] c = new int[Q + 1];
		int[] d = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextInt();
			d[i] = sc.nextInt();
		}

		// 文字列のハッシュの準備
		StringHash Z = new StringHash(S);

		// クエリに答える
		for (int i = 1; i <= Q; i++) {
			long hash1 = Z.hashValue(a[i], b[i]);
			long hash2 = Z.hashValue(c[i], d[i]);
			if (hash1 == hash2) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
	}

	// 文字列のハッシュを実装したクラス StringHash
	static class StringHash {
		static final int MOD = 2147483647;
		long[] power100;
		long[] h;
		StringHash(String S) {
			int N = S.length();
			// 文字列を数値に変換
			int[] T = new int[N + 1];
			for (int i = 1; i <= N; i++) {
				T[i] = (int)(S.charAt(i - 1) - 'a') + 1;
			}
			// 100 の n 乗（本文中の B^0, B^1, ... に対応）を前計算する
			power100 = new long[N + 1];
			power100[0] = 1;
			for (int i = 1; i <= N; i++) {
				power100[i] = power100[i - 1] * 100 % MOD;
			}
			// H[1], H[2], ..., H[N] を前計算する
			h = new long[N + 1];
			h[0] = 1;
			for (int i = 1; i <= N; i++) {
				h[i] = (h[i - 1] * 100 + T[i]) % MOD;
			}
		}
		// S[l, r] のハッシュ値を返す関数
		// 余りの計算に注意！（5.3 節）
		long hashValue(int l, int r) {
			long val = h[r] - h[l - 1] * power100[r - l + 1] % MOD;
			if (val < 0) {
				val += MOD;
			}
			return val;
		}
	}
}