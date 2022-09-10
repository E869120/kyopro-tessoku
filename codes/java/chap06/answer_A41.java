import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力
		int N = sc.nextInt();
		String S = sc.next();

		// 答えを求める
		boolean Answer = false;
		for (int i = 0; i <= N - 3; i++) {
			if (S.charAt(i)=='R' && S.charAt(i+1)=='R' && S.charAt(i+2)=='R') Answer = true;
			if (S.charAt(i)=='B' && S.charAt(i+1)=='B' && S.charAt(i+2)=='B') Answer = true;
		}

		// 出力
		if (Answer == true) System.out.println("Yes");
		else System.out.println("No");
	}
};
