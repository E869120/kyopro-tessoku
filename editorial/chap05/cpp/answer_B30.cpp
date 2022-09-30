#include <iostream>
using namespace std;

// a の b 乗を m で割った余りを返す関数
// 変数 a は a^1 → a^2 → a^4 → a^8 → a^16 → ･･･ と変化
long long Power(long long a, long long b, long long m) {
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		int wari = (1 << i);
		if ((b / wari) % 2 == 1) {
			Answer = (Answer * p) % m; // 「a の 2^i 乗」が掛けられるとき
		}
		p = (p * p) % m;
	}
	return Answer;
}

// a ÷ b を m で割った余りを返す関数
long long Division(long long a, long long b, long long m) {
	return (a * Power(b, m - 2, m)) % m;
}

// nCr mod 1000000007 を返す関数
long long ncr(int n, int r) {
	const long long M = 1000000007;

	// 手順 1: 分子 a を求める
	long long a = 1;
	for (int i = 1; i <= n; i++) a = (a * i) % M;

	// 手順 2: 分母 b を求める
	long long b = 1;
	for (int i = 1; i <= r; i++) b = (b * i) % M;
	for (int i = 1; i <= n - r; i++) b = (b * i) % M;

	// 手順 3: 答えを求める
	return Division(a, b, M);
}

int main() {
	// 入力
	long long H, W;
	cin >> H >> W;

	// 出力
	cout << ncr(H + W - 2, W - 1) << endl;
	return 0;
}
