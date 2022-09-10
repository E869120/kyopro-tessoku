// x が素数のとき true を、素数ではないとき false を返す
bool isPrime(int x) {
	for (int i = 2; i <= x - 1; i++) {
		if (x % i == 0) return false;
	}
	return true;
}
