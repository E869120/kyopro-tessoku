#include <iostream>
using namespace std;

// a の b 乗を m で割った余りを返す関数
long long Power(long long a, long long b, long long m) {
	long long p = a, Answer = 1;
	for (int i = 0; i < 60; i++) {
		long long wari = (1LL << i);
		if ((b / wari) % 2 == 1) {
			Answer = (Answer * p) % m;
		}
		p = (p * p) % m;
	}
	return Answer;
}

int main() {
	// 入力
	const long long mod = 1000000007;
	long long W;
	cin >> W;

	// 出力
	cout << 12LL * Power(7, W - 1, mod) % mod << endl;
	return 0;
}
