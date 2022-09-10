import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();

		// Grundy 数を求める
		// 変数 grundy[i] : 石が i 個の時の Grundy 数
		// 変数 Transit[i]: Grundy 数が i となるような遷移ができるか
		int[] grundy = new int[100001];
		for (int i = 0; i <= 100000; i++) {
			boolean[] Transit = {false, false, false};
			if (i >= X) Transit[grundy[i-X]] = true;
			if (i >= Y) Transit[grundy[i-Y]] = true;
			if (Transit[0] == false) grundy[i] = 0;
			else if (Transit[1] == false) grundy[i] = 1;
			else grundy[i] = 2;
	  }
		
		// 出力
		int XOR_Sum = 0;
		for (int i = 1; i <= N; i++) XOR_Sum = (XOR_Sum ^ grundy[A[i]]);
		if (XOR_Sum != 0) System.out.println("First");
		if (XOR_Sum == 0) System.out.println("Second");
	}
};
