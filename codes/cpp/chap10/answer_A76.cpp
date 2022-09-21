#include <iostream>
#include <algorithm>
using namespace std;

const long long mod = 1000000007;
long long N, W, L, R, X[150009];
int dp[150009], sum[150009];

int main() {
	// 入力
	cin >> N >> W >> L >> R;
	for (int i = 1; i <= N; i++) cin >> X[i];

	// 西岸を足場 0、東岸を足場 N+1 とみなす
	X[0] = 0; X[N + 1] = W;

	// 動的計画法・出力
	dp[0] = 1; sum[0] = 1;
	for (int i = 1; i <= N + 1; i++) {
		int posL = lower_bound(X, X + N + 2, X[i] - R) - X;
		int posR = lower_bound(X, X + N + 2, X[i] - L + 1) - X; posR--;

		// dp[i] の値を累積和で計算（引き算の余りに注意！）
		if (posR == -1) dp[i] = 0;
		else dp[i] = sum[posR];
		if (posL >= 1) dp[i] -= sum[posL - 1];
		dp[i] = (dp[i] + mod) % mod;

		// 累積和 sum[i] を更新
		sum[i] = sum[i - 1] + dp[i];
		sum[i] %= mod;
	}
	cout << dp[N + 1] << endl;
	return 0;
}
