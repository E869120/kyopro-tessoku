#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
int N, X[19], Y[19];
double dp[1 << 16][19];
 
int main() {
	// 入力
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
 
	// 配列 dp の初期化
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) dp[i][j] = 1e9;
	}
 
	// 動的計画法（dp[通った都市][今いる都市] となっている）
	dp[0][0] = 0;
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] >= 1e9) continue;
 
			// 都市 j から都市 k に移動したい！
			for (int k = 0; k < N; k++) {
				// 既に都市 k を通っていた場合
				if ((i / (1 << k)) % 2 == 1) continue;
 
				// 状態遷移
				double DIST = sqrt(1.0 * (X[j] - X[k]) * (X[j] - X[k]) + 1.0 * (Y[j] - Y[k]) * (Y[j] - Y[k]));
				dp[i + (1 << k)][k] = min(dp[i + (1 << k)][k], dp[i][j] + DIST);
			}
		}
	}
 
	// 答えを出力
	printf("%.12lf\n", dp[(1 << N) - 1][0]);
	return 0;
}
