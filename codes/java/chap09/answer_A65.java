import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 入力（高速な入出力のため、Scanner の代わりに BufferedReader を使っています）
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int[] A = new int[N + 1];
		st = new StringTokenizer(buff.readLine());
		for (int i = 2; i <= N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		
		// 隣接リストの作成
		ArrayList<Integer>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 2; i <= N; i++) {
			G[A[i]].add(i); // 「上司→部下」の方向に辺を追加
		}

		// 動的計画法（dp[x] は社員 x の部下の数）
		int[] dp = new int[N + 1]; // Java では new で初期化した配列の要素は 0 になることに注意
		for (int i = N; i >= 1; i--) {
			for (int j = 0; j < G[i].size(); j++) {
				dp[i] += (dp[G[i].get(j)] + 1);
			}
		}
		
		// 答えを空白区切りで出力（高速な出力のため、System.out.println ではなく PrintWriter を使っています）
		PrintWriter output = new PrintWriter(System.out);
		for (int i = 1; i <= N; i++) {
			if (i >= 2) {
				output.print(" ");
			}
			output.print(dp[i]);
		}
		output.println();
		output.flush();
	}
}