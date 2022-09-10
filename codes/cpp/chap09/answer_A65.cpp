#include <iostream>
#include <vector>
using namespace std;

int N, A[100009], dp[100009];
vector<int> G[100009];

int main() {
	// 入力
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> A[i];
		G[A[i]].push_back(i); // 「上司→部下」の方向に辺を追加
	}
	// 動的計画法（dp[x] は社員 x の部下の数）
	for (int i = N; i >= 1; i--) {
		dp[i] = 0;
		for (int j = 0; j < G[i].size(); j++) dp[i] += (dp[G[i][j]] + 1);
	}
	// 空白区切りで出力
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << dp[i];
	}
	cout << endl;
	return 0;
}
