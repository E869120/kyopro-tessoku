// ###########################
// # 配列 dp を使わない実装
// ###########################

#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009];
int LEN = 0, L[100009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 動的計画法
	for (int i = 1; i <= N; i++) {
		int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
		L[pos] = A[i];
		if (pos > LEN) LEN += 1;
	}

	// 答えを出力
	cout << LEN << endl;
	return 0;
}
