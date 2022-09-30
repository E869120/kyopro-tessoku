#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 入力・グラフ
int N, M, A[100009], B[100009], C[100009];
vector<pair<int, int>> G[100009];

// ダイクストラ法
int cur[100009]; bool kakutei[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

// 頂点 1 からの距離、頂点 N からの距離
int dist1[100009];
int distN[100009];

// 始点 start でダイクストラ法を行う関数
void dijkstra(int start) {
	// 配列の初期化
	for (int i = 1; i <= N; i++) kakutei[i] = false;
	for (int i = 1; i <= N; i++) cur[i] = 2000000000;

	// スタート地点をキューに追加
	cur[start] = 0;
	Q.push(make_pair(cur[start], start));

	// ダイクストラ法
	while (!Q.empty()) {
		// 次に確定させるべき頂点を求める
		int pos = Q.top().second; Q.pop();
		if (kakutei[pos] == true) continue;

		// cur[x] の値を更新する
		kakutei[pos] = true;
		for (int i = 0; i < G[pos].size(); i++) {
			int nex = G[pos][i].first;
			int cost = G[pos][i].second;
			if (cur[nex] > cur[pos] + cost) {
				cur[nex] = cur[pos] + cost;
				Q.push(make_pair(cur[nex], nex));
			}
		}
	}
}

int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i];
		G[A[i]].push_back(make_pair(B[i], C[i]));
		G[B[i]].push_back(make_pair(A[i], C[i]));
	}

	// ダイクストラ法を行う
	dijkstra(1); for (int i = 1; i <= N; i++) dist1[i] = cur[i];
	dijkstra(N); for (int i = 1; i <= N; i++) distN[i] = cur[i];

	// 答えを求める
	int Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (dist1[i] + distN[i] == dist1[N]) Answer += 1;
	}

	// 出力
	cout << Answer << endl;
	return 0;
}
