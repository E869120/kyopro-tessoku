#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 入力・グラフを表す変数
int N, M, A[100009], B[100009], C[100009], D[100009];
vector<pair<int, int>> G[8009];

// ダイクストラ法で使う変数
long long cur[8009]; bool kakutei[8009];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;

int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		if (D[i] == 1) {
			G[A[i]].push_back(make_pair(B[i], 10000 * C[i] - 1));
			G[B[i]].push_back(make_pair(A[i], 10000 * C[i] - 1));
		}
		else {
			G[A[i]].push_back(make_pair(B[i], 10000 * C[i]));
			G[B[i]].push_back(make_pair(A[i], 10000 * C[i]));
		}
	}

	// 配列の初期化
	for (int i = 1; i <= N; i++) kakutei[i] = false;
	for (int i = 1; i <= N; i++) cur[i] = (1LL << 60);

	// スタート地点をキューに追加
	cur[1] = 0;
	Q.push(make_pair(cur[1], 1));

	// ダイクストラ法
	while (!Q.empty()) {
		// 次に確定させるべき頂点を求める
		int pos = Q.top().second; Q.pop();
		if (kakutei[pos] == true) continue;

		// cur[nex] の値を更新する
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

	// 答えを出力
	// マラソンコースの距離：cur[N]/10000 を小数点以下切り上げた値
	// コース上の木の数：cur[N] と Distance*10000 の差分
	long long Distance = (cur[N] + 9999) / 10000;
	long long NumTrees = Distance * 10000 - cur[N];
	cout << Distance << " " << NumTrees << endl;
	return 0;
}
