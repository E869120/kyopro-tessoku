import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// ε₯ε
		int N = sc.nextInt();
		int K = sc.nextInt();

		// εΊε
		if (K >= 2*N-2 && K%2 == 0) System.out.println("Yes");
		else System.out.println("No");
	}
};
