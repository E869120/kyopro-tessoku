#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int M, A[59], B[59];
int dp[19][309];

// l ページ目から r ページ目までの間に、何個のつながりがあるか？
int tsunagari(int l, int r) {
	int cnt = 0;
	for (int i = 1; i <= M; i++) {
		if (l <= A[i] && B[i] <= r) cnt++;
	}
	return cnt;
}

int main() {
	// 入力
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i];

	// 配列 dp の初期化
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= N; j++) dp[i][j] = -1000000;
	}

	// 動的計画法（貰う遷移形式）
	dp[0][0] = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			// k は「前の章がどのページで終わったか」
			for (int k = 0; k <= j - 1; k++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + tsunagari(k + 1, j));
			}
		}
	}

	// 出力
	cout << dp[K][N] << endl;
	return 0;
}
