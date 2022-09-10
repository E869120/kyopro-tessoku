#include <iostream>
using namespace std;

int N, X, Y, A[100009];
int grundy[100009];

int main() {
	// [ 入力 ]
	cin >> N >> X >> Y;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// [Grundy 数を求める ]
	// 変数 grundy[i] : 石が i 個の時の Grundy 数
	// 変数 Transit[i]: Grundy 数が i となるような遷移ができるか
	for (int i = 0; i <= 100000; i++) {
		bool Transit[3] = { false, false, false };
		if (i >= X) Transit[grundy[i - X]] = true;
		if (i >= Y) Transit[grundy[i - Y]] = true;
		if (Transit[0] == false) grundy[i] = 0;
		else if (Transit[1] == false) grundy[i] = 1;
		else grundy[i] = 2;
	}

	// [ 出力 ]
	int XOR_Sum = 0;
	for (int i = 1; i <= N; i++) XOR_Sum = (XOR_Sum ^ grundy[A[i]]);
	if (XOR_Sum != 0) cout << "First" << endl;
	if (XOR_Sum == 0) cout << "Second" << endl;
	return 0;
}
