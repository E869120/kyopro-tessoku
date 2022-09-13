import java.util.*;

class Main {
	public static void main(String[] args) {
		// 入力
		Scanner sc = new Scanner(System.in);
		final int N = 20;
		int T = sc.nextInt();
		int[] P = new int[T + 1];
		int[] Q = new int[T + 1];
		int[] R = new int[T + 1];
		for (int i = 1; i <= T; i++) {
			P[i] = sc.nextInt();
			Q[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}
		
		// ビームサーチ（書籍とは異なり、ビームサーチの復元は関数の中で行う）
		char[] answer = beamSearch(N, T, P, Q, R);

		// 答えの出力
		for (int i = 1; i <= T; i++) {
			System.out.println(answer[i]);
		}
	}

	// ビームサーチを行う関数
	static char[] beamSearch(int N, int T, int[] P, int[] Q, int[] R) {
		// 2 次元配列 beam を用意し、0 手目の状態を設定
		final int WIDTH = 7000; // WIDTH はビーム幅
		ArrayList<State>[] beam = new ArrayList[T + 1];
		beam[0] = new ArrayList<>();
		beam[0].add(new State(N));

		// ビームサーチ
		for (int i = 1; i <= T; i++) {
			ArrayList<State> candidate = new ArrayList<>();
			for (int j = 0; j < beam[i - 1].size(); j++) {
				// 操作 A の場合
				State sousaA = new State(beam[i - 1].get(j));
				sousaA.lastMove = 'A';
				sousaA.lastPos = j;
				sousaA.x[P[i]] += 1;
				sousaA.x[Q[i]] += 1;
				sousaA.x[R[i]] += 1;
				for (int k = 1; k <= N; k++) {
					if (sousaA.x[k] == 0) {
						sousaA.score += 1;
					}
				}
				// 操作 B の場合
				State sousaB = new State(beam[i - 1].get(j));
				sousaB.lastMove = 'B';
				sousaB.lastPos = j;
				sousaB.x[P[i]] -= 1;
				sousaB.x[Q[i]] -= 1;
				sousaB.x[R[i]] -= 1;
				for (int k = 1; k <= N; k++) {
					if (sousaB.x[k] == 0) {
						sousaB.score += 1;
					}
				}
				// 候補に追加
				candidate.add(sousaA);
				candidate.add(sousaB);
			}
			// ソートして beam[i] の結果を計算する
			Collections.sort(candidate);
			beam[i] = new ArrayList<State>(candidate.subList(0, Math.min(candidate.size(), WIDTH)));
		}

		// ビームサーチの復元（currentPlace は配列 beam のどの位置を見ているかを表す）
		char[] answer = new char[T + 1];
		int currentPlace = 0;
		for (int i = T; i >= 1; i--) {
			answer[i] = beam[i].get(currentPlace).lastMove;
			currentPlace = beam[i].get(currentPlace).lastPos;
		}

		return answer;
	}

	// 盤面の状態を表す構造体 State
	static class State implements Comparable<State> {
		int score;     // 暫定スコア
		int[] x;       // 現在の配列 X の値
		char lastMove; // 最後の動き（'A' または 'B'）
		int lastPos;   // Beam[i-1][どこ] から遷移したか
		// 盤面の状態の初期化
		public State(int N) {
			score = 0;
			x = new int[N + 1];
			lastMove = '?';
			lastPos = -1;
		}
		// コピーコンストラクタ
		public State(State s) {
			score = s.score;
			x = s.x.clone();
			lastMove = s.lastMove;
			lastPos = s.lastPos;
		}
		@Override public int compareTo(State s) {
			return s.score - score; // ソートの際は、self.score > s.score のとき self が s よりも前に来るようにする
		}
	}
}