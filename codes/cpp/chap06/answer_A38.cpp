#include <iostream>
#include <algorithm>
using namespace std;

int D, N;
int L[10009], R[10009], H[10009], LIM[10009];

int main() {
	// 入力
	cin >> D >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i] >> H[i];

	// 配列の初期化（1 日は 24 時間）
	for (int i = 1; i <= D; i++) LIM[i] = 24;

	// 上限値を求める
	for (int i = 1; i <= N; i++) {
		for (int j = L[i]; j <= R[i]; j++) LIM[j] = min(LIM[j], H[i]);
	}

	// 答えを出力
	int Answer = 0;
	for (int i = 1; i <= D; i++) Answer += LIM[i];
	cout << Answer << endl;
	return 0;
}
