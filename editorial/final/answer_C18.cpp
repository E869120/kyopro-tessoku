#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, A[409];
int dp[409][409];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= 2 * N; i++) cin >> A[i];

	// 配列 dp の初期化
	for (int i = 1; i <= 2 * N; i++) {
		for (int j = 1; j <= 2 * N; j++) dp[i][j] = 1000000000;
	}
	
	// 動的計画法（初期状態）
	for (int i = 1; i <= 2 * N - 1; i++) {
		dp[i][i + 1] = abs(A[i] - A[i + 1]);
	}

	// 動的計画法（遷移）
	for (int LEN = 2; LEN <= 2 * N - 1; LEN++) {
		for (int l = 1; l <= 2 * N - LEN; l++) {
			int r = l + LEN;

			// l 番目と r 番目を消す場合
			dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + abs(A[l] - A[r]));

			// 2 つの区間を合成させる場合
			for (int m = l; m < r; m++) {
				dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
			}
		}
	}

	// 出力
	cout << dp[1][2 * N] << endl;
	return 0;
}
