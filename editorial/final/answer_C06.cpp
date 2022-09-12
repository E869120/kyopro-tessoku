#include <iostream>
using namespace std;

int main() {
	// 入力
	int N;
	cin >> N;

	// 出力
	cout << N << endl;
	for (int i = 1; i <= N; i++) {
		cout << i << " " << i % N + 1 << endl;
	}
	return 0;
}
