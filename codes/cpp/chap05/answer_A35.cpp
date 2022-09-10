#include <iostream>
#include <algorithm>
using namespace std;

int N, A[2009];
int dp[2009][2009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 動的計画法 [N 段目 ]
	for (int j = 1; j <= N; j++) dp[N][j] = A[j];

	// 動的計画法 [1 ～ N-1 段目 ]
	for (int i = N - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			if (i % 2 == 1) dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
			if (i % 2 == 0) dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}

	// 出力
	cout << dp[1][1] << endl;
	return 0;
}
