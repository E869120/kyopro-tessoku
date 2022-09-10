#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T[109], D[109];
int dp[109][1449], Answer = 0;

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> T[i] >> D[i];

	// D[i] の小さい順に並べ替える
	vector<pair<int, int>> Problems;
	for (int i = 1; i <= N; i++) Problems.push_back(make_pair(D[i], T[i]));
	sort(Problems.begin(), Problems.end());
	for (int i = 1; i <= N; i++) {
		D[i] = Problems[i - 1].first;
		T[i] = Problems[i - 1].second;
	}

	// 配列の初期化
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 1440; j++) dp[i][j] = -1;
	}

	// 動的計画法
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 1440; j++) {
			if (j > D[i] || j < T[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - T[i]] + 1);
		}
	}

	// 答えを出力
	for (int i = 0; i <= 1440; i++) Answer = max(Answer, dp[N][i]);
	cout << Answer << endl;
	return 0;
}
