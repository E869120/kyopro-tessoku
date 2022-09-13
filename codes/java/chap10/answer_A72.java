import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力（書籍とは異なり c[i][j] は 0-indexed で入力しています）
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int K = sc.nextInt();
		char[][] c = new char[H][W];
		for (int i = 0; i < H; i++) {
			String cs = sc.next();
			for (int j = 0; j < W; j++) {
				c[i][j] = cs.charAt(j);
			}
		}

		// ビット全探索
		int answer = 0;
		for (int t = 0; t < (1 << H); t++) {
			// まずはマス目を初期盤面に設定
			char[][] d = new char[H][W];
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					d[i][j] = c[i][j];
				}
			}

			// 行に対して操作を行う
			// 変数 remainingSteps は残り操作回数
			int remainingSteps = K;
			for (int i = 0; i < H; i++) {
				int wari = (1 << i);
				if ((t / wari) % 2 == 1) {
					remainingSteps -= 1;
					for (int j = 0; j < W; j++) {
						d[i][j] = '#';
					}
				}
			}

			// 列に対して操作を行う
			if (remainingSteps >= 0) {
				int subAnswer = paintRow(H, W, d, remainingSteps);
				answer = Math.max(answer, subAnswer);
			}
		}

		// 出力
		System.out.println(answer);
	}

	// 残り remainingSteps 回の「列に対する操作」で、最大何個のマスを黒くできるかを返す関数
	static int paintRow(int H, int W, char[][] d, int remainingSteps) {
		// 各列に対する「白マスの個数」を計算し、大きい順にソートする
		PairInt[] column = new PairInt[W];
		for (int j = 0; j < W; j++) {
			int cnt = 0;
			for (int i = 0; i < H; i++) {
				if (d[i][j] == '.') {
					cnt += 1;
				}
			}
			column[j] = new PairInt(cnt, j);
		}
		Arrays.sort(column, Collections.reverseOrder());

		// 列に対して操作を行う
		for (int j = 0; j < remainingSteps; j++) {
			int idx = column[j].second;
			for (int i = 0; i < H; i++) {
				d[i][idx] = '#';
			}
		}

		// 黒マスの個数を数える
		int ret = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (d[i][j] == '#') {
					ret += 1;
				}
			}
		}
		return ret;
	}

	// int 型のペアのクラス PairInt
	static class PairInt implements Comparable<PairInt> {
		int first, second;
		public PairInt(int first, int second) {
			this.first = first;
			this.second = second;
		}
		@Override public int compareTo(PairInt p) {
			// PairInt 型同士の比較をする関数
			if (this.first < p.first || (this.first == p.first && this.second < p.second)) {
				return -1;
			}
			if (this.first > p.first || (this.first == p.first && this.second > p.second)) {
				return 1;
			}
			return 0;
		}
	}
}