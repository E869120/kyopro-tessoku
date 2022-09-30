#include <iostream>
using namespace std;

int H, W;
int N, A[200009], B[200009];

int main() {
	// 入力
	cin >> N >> H >> W;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

	// 全部 XOR した値（ニム和）を求める
	int XOR_Sum = 0;
	for (int i = 1; i <= N; i++) XOR_Sum = (XOR_Sum ^ (A[i] - 1));
	for (int i = 1; i <= N; i++) XOR_Sum = (XOR_Sum ^ (B[i] - 1));

	// 出力
	if (XOR_Sum != 0) cout << "First" << endl;
	if (XOR_Sum == 0) cout << "Second" << endl;
	return 0;
}
