#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009], B[100009];
int dp[100009];

int main() {
	// 入力
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> A[i];
	for (int i = 3; i <= N; i++) cin >> B[i];

	// 配列 dp の初期化
	dp[1] = 0;
	for (int i = 2; i <= N; i++) dp[i] = 2000000000;

	// 動的計画法
	for (int i = 1; i <= N; i++) {
		if (i <= N - 1) dp[i + 1] = min(dp[i + 1], dp[i] + A[i + 1]); // 部屋 i+1 に行く場合
		if (i <= N - 2) dp[i + 2] = min(dp[i + 2], dp[i] + B[i + 2]); // 部屋 i+2 に行く場合
	}

	// 出力
	cout << dp[N] << endl;
	return 0;
}
