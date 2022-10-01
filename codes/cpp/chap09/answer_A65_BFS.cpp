// ###############################
// # 幅優先探索を使った実装
// ###############################

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, A[100009], dp[100009];
vector<int> G[100009];
int dist[100009]; // 距離

// 頂点 1 から各頂点までの距離を求める関数
void GetDistance() {
	queue<int> Q;
	for (int i = 1; i <= N; i++) dist[i] = -1;
	Q.push(1);
	dist[1] = 0;

	// キューを使った計算
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int i = 0; i < G[pos].size(); i++) {
			int to = G[pos][i];
			if (dist[to] == -1) {
				dist[to] = dist[pos] + 1;
				Q.push(to);
			}
		}
	}
}

int main() {
	// 入力
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> A[i];
		G[A[i]].push_back(i);
	}

	// 頂点 1 からの距離を求める
	GetDistance();

	// 距離の大きい順にソートする
	vector<pair<int, int>> List;
	for (int i = 1; i <= N; i++) {
		List.push_back(make_pair(dist[i], i));
	}
	sort(List.begin(), List.end());
	reverse(List.begin(), List.end());

	// 動的計画法（dp[x] は社員 x の部下の数）
	for (int i = 0; i < List.size(); i++) {
		int idx = List[i].second;
		dp[idx] = 0;
		for (int j = 0; j < G[idx].size(); j++) dp[idx] += (dp[G[idx][j]] + 1);
	}

	// 空白区切りで出力
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << dp[i];
	}
	cout << endl;
	return 0;
}
