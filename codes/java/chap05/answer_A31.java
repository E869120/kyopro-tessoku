import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long N = sc.nextLong();
		long A1 = N /  3; // 3 で割り切れるものの個数
		long A2 = N /  5; // 5 で割り切れるものの個数
		long A3 = N / 15; // 3, 5 両方で割り切れるもの（= 15 の倍数）の個数
		System.out.println(A1 + A2 - A3);
	}
};
