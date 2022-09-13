import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 入力（高速な入力のため、Scanner の代わりに BufferedReader を使っています）
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int[] A = new int[N + 1];
		st = new StringTokenizer(buff.readLine());
		for (int i = 1; i <= N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}

		// スタックの変化の再現
		int[] answer = new int[N + 1];
		Stack<PairInt> level2 = new Stack<>();
		for (int i = 1; i <= N; i++) {
			if (i >= 2) {
				level2.push(new PairInt(i - 1, A[i - 1]));
				while (!level2.empty()) {
					int kabuka = level2.peek().second;
					if (kabuka <= A[i]) {
						level2.pop();
					}
					else {
						break;
					}
				}
			}
			// 起算日の特定
			if (!level2.empty()) {
				answer[i] = level2.peek().first;
			}
			else {
				answer[i] = -1;
			}
		}

		// 出力（高速な出力のため、System.out.println ではなく PrintWriter を使っています）
		PrintWriter output = new PrintWriter(System.out);
		for (int i = 1; i <= N; i++) {
			if (i >= 2) {
				output.print(" ");
			}
			output.print(answer[i]);
		}
		output.println();
		output.flush();
	}
	
	// int 型のペアのクラス PairInt
	static class PairInt {
		int first, second;
		public PairInt(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
}