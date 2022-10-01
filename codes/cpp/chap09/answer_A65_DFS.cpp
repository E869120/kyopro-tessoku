// ###############################
// # 深さ優先探索を使った実装
// ###############################

#include <iostream>
#include <vector>
using namespace std;

int N, A[100009], dp[100009];
vector<int> G[100009];

void dfs(int pos) {
	// 再帰的に計算する
	for (int i = 0; i < G[pos].size(); i++) {
		int to = G[pos][i]; // to は直属の部下の番号
		dfs(to);
		dp[pos] += (dp[to] + 1);
	}
}

int main() {
	// 入力
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> A[i];
		G[A[i]].push_back(i); // 「上司→部下」の方向に辺を追加
	}

	// 深さ優先探索
	dfs(1);

	// 空白区切りで出力
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << dp[i];
	}
	cout << endl;
	return 0;
}
