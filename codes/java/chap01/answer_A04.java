import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();

		// 上の桁から順番に「2 進法に変換した値」を求める
		for (int x = 9; x >= 0; x--) {
			int wari = (1 << x); // 2 の x 乗
			System.out.print((N / wari) % 2); // 割り算の結果に応じて 0 または 1 の出力
		}
		System.out.println(); // 最後に改行する
	}
};
