import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		char C = sc.next().charAt(0);
		String A = sc.next();

		// スコアの計算
		int score = 0;
		for (int i = 0; i < N; i++) {
			if (A.charAt(i) == 'W') score += 0;
			if (A.charAt(i) == 'B') score += 1;
			if (A.charAt(i) == 'R') score += 2;
		}

		// 出力
		if (score % 3 == 0 && C == 'W') System.out.println("Yes");
		else if (score % 3 == 1 && C == 'B') System.out.println("Yes");
		else if (score % 3 == 2 && C == 'R') System.out.println("Yes");
		else System.out.println("No");
	}
};
