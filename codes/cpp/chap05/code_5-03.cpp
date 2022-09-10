// 整数 A と B の最大公約数を返す関数
// GCD は最大公約数（Greatest Common Divisor）の略
int GCD(int A, int B) {
	int ret = 0;
	for (int x = 1; x <= min(A, B); x++) {
		if (A % x == 0 && B % x == 0) ret = x;
	}
	return ret;
}
