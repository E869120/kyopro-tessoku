#include <iostream>
using namespace std;

const int mod = 1000000007;
int N, a[10000009];

int main() {
	// 入力
	cin >> N;

	// フィボナッチ数列の計算
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i <= N; i++) {
		a[i] = (a[i - 1] + a[i - 2]) % mod;
	}

	// 出力
	cout << a[N] << endl;
	return 0;
}
