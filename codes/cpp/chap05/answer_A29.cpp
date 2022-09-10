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

int main() {
	long long a, b;
	cin >> a >> b;
	cout << Power(a, b, 1000000007) << endl;
	return 0;
}
