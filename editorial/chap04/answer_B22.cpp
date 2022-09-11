#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, H[100009];
int dp[100009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> H[i];

	// 配列 dp の初期化
	dp[1] = 0;
	for (int i = 2; i <= N; i++) dp[i] = 2000000000;

	// 動的計画法
	for (int i = 1; i <= N; i++) {
		if (i <= N - 1) dp[i + 1] = min(dp[i + 1], dp[i] + abs(H[i + 1] - H[i])); // 足場 i+1 に行く場合
		if (i <= N - 2) dp[i + 2] = min(dp[i + 2], dp[i] + abs(H[i + 2] - H[i])); // 足場 i+2 に行く場合
	}

	// 出力
	cout << dp[N] << endl;
	return 0;
}
