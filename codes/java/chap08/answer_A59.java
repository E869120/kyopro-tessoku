import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		int[] queryType = new int[Q + 1];
		int[] pos = new int[Q + 1];
		int[] x = new int[Q + 1];
		int[] l = new int[Q + 1];
		int[] r = new int[Q + 1];
		for (int i = 1; i <= Q; i++) {
			queryType[i] = sc.nextInt();
			if (queryType[i] == 1) {
				pos[i] = sc.nextInt();
				x[i] = sc.nextInt();
			}
			if (queryType[i] == 2) {
				l[i] = sc.nextInt();
				r[i] = sc.nextInt();
			}
		}

		// クエリの処理
		SegmentTree Z = new SegmentTree(N);
		for (int i = 1; i <= Q; i++) {
			if (queryType[i] == 1) {
				Z.update(pos[i], x[i]);
			}
			if (queryType[i] == 2) {
				// 最初のセルに対応する半開区間は [1, size + 1)
				System.out.println(Z.query(l[i], r[i], 1, Z.size + 1, 1));
			}
		}
	}

	// セグメント木を実装したクラス SegmentTree
	static class SegmentTree {
		int size;
		int[] dat;
		// 要素 dat の初期化を行う（最初は全部ゼロ）
		SegmentTree(int n) {
			size = 1;
			while (size < n) {
				size *= 2;
			}
			dat = new int[size * 2]; // Java では new で初期化した配列の要素は 0 になることに注意
		}
		// クエリ 1 に対する処理
		void update(int pos, int x) {
			pos += size - 1;
			dat[pos] = x;
			while (pos >= 2) {
				pos /= 2;
				dat[pos] = dat[pos * 2] + dat[pos * 2 + 1]; // 8.8 節から変更した部分
			}
		}
		// クエリ 2 に対する処理
		// u は現在のセル番号、[a, b) はセルに対応する半開区間、[l, r) は求めたい半開区間
		int query(int l, int r, int a, int b, int u) {
			if (r <= a || b <= l) {
				return 0; // 8.8 節から変更した部分
			}
			if (l <= a && b <= r) {
				return dat[u];
			}
			int m = (a + b) / 2;
			int answerL = query(l, r, a, m, u * 2);
			int answerR = query(l, r, m, b, u * 2 + 1);
			return answerL + answerR; // 8.8 節から変更した部分
		}
	}
}