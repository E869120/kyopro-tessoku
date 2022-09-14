#include <iostream>
#include <algorithm>
using namespace std;

int N, M, A[109][19];
int dp[109][1024];

int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) cin >> A[i][j];
	}

	// 配列の初期化
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j < (1 << N); j++) dp[i][j] = 1'000'000'000;
	}

	// 動的計画法
	dp[0][0] = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < (1 << N); j++) {
			// already[k] = 1 のとき、品物 k は既に無料になっている
			int already[19];
			for (int k = 1; k <= N; k++) {
				if ((j / (1 << (k - 1))) % 2 == 0) already[k] = 0;
				else already[k] = 1;
			}

			// クーポン券 i を選んだ場合の整数表現 v を計算する
			int v = 0;
			for (int k = 1; k <= N; k++) {
				if (already[k] == 1 || A[i][k] == 1) v += (1 << (k - 1));
			}

			// 遷移を行う
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			dp[i][v] = min(dp[i][v], dp[i - 1][j] + 1);
		}
	}

	// 出力（すべて選んだ場合の整数表現は 2^N-1）
	if (dp[M][(1 << N) - 1] == 1'000'000'000) cout << "-1" << endl;
	else cout << dp[M][(1 << N) - 1] << endl;
	return 0;
}
