#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int N, M, dp[2009][2009];
string S, T;
 
int main() {
	// 入力
	cin >> S; N = S.size();
	cin >> T; M = T.size();
 
	// 動的計画法
	dp[0][0] = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i >= 1 && j >= 1 && S[i - 1] == T[j - 1]) {
				dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] });
			}
			else if (i >= 1 && j >= 1) {
				dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1 });
			}
			else if (i >= 1) {
				dp[i][j] = dp[i - 1][j] + 1;
			}
			else if (j >= 1) {
				dp[i][j] = dp[i][j - 1] + 1;
			}
		}
	}
 
	// 出力
	cout << dp[N][M] << endl;
	return 0;
}
