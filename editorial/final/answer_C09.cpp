#include <iostream>
#include <algorithm>
using namespace std;

long long N, A[500009];
long long dp[500009][2];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 動的計画法（i=1）
	dp[1][0] = 0;
	dp[1][1] = A[1];

	// 動的計画法（i>=2）
	for (int i = 2; i <= N; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + A[i];
	}
	
	// 出力
	cout << max(dp[N][0], dp[N][1]) << endl;
	return 0;
}
