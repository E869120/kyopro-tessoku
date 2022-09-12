#include <iostream>
using namespace std;

int main() {
	// 入力
	int N;
	cin >> N; N -= 1;

	// 出力
	for (int x = 9; x >= 0; x--) {
		int wari = (1 << x);
		if ((N / wari) % 2 == 0) cout << "4"; // 2 進法の 0 が 4 に対応
		if ((N / wari) % 2 == 1) cout << "7"; // 2 進法の 1 が 7 に対応
	}
	cout << endl;
	return 0;
}
