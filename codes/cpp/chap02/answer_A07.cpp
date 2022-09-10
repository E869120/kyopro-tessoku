#include <iostream>
using namespace std;

int N, L[100009], R[100009];
int D, B[100009];
int Answer[100009];

int main() {
	// 入力
	cin >> D >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// 前日比に加算
	for (int i = 1; i <= N; i++) {
		B[L[i]] += 1;
		B[R[i] + 1] -= 1;
	}

	// 累積和をとる → 出力
	Answer[0] = 0;
	for (int d = 1; d <= D; d++) Answer[d] = Answer[d - 1] + B[d];
	for (int d = 1; d <= D; d++) cout << Answer[d] << endl;
	return 0;
}
