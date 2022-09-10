#include <iostream>
using namespace std;

int main() {
	// 入力
	int N, K, A[22];
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 全探索（sum は書かれた整数の合計／ Answer は現時点での答え）
	bool Answer = false;
	for (int i = 0; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			int wari = (1 << (j - 1));
			if ((i / wari) % 2 == 1) sum += A[j];
		}
		if (sum == K) Answer = true;
	}

	// 出力
	if (Answer == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
