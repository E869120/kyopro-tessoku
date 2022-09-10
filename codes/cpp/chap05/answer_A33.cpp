#include <iostream>
using namespace std;

int N, A[100009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 全部 XOR した値（ニム和）を求める
	int XOR_Sum = A[1];
	for (int i = 2; i <= N; i++) XOR_Sum = (XOR_Sum ^ A[i]);

	// 出力
	if (XOR_Sum != 0) cout << "First" << endl;
	if (XOR_Sum == 0) cout << "Second" << endl;
	return 0;
}
