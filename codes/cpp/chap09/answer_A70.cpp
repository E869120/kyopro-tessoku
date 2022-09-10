#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, A[19];
int M, X[109], Y[109], Z[109];
int dist[1033];
vector<int> G[1033];

// 頂点 pos の状態から「idx 種類目の操作」を行ったときの頂点番号を返す
int GetNext(int pos, int idx) {
	int State[19]; // State[i] はランプ i の状態

	// 2 進法に直す方法は 1.4 節を参照
	for (int i = 1; i <= N; i++) {
		int wari = (1 << (i - 1));
		State[i] = (pos / wari) % 2;
	}
	State[X[idx]] = 1 - State[X[idx]]; // ランプ X[idx] を反転
	State[Y[idx]] = 1 - State[Y[idx]]; // ランプ Y[idx] を反転
	State[Z[idx]] = 1 - State[Z[idx]]; // ランプ Z[idx] を反転

	// 10 進法に変換する方法も 1.4 節を参照
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (State[i] == 1) ret += (1 << (i - 1));
	}
	return ret;
}

int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int j = 1; j <= M; j++) cin >> X[j] >> Y[j] >> Z[j];

	// グラフに辺を追加
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 1; j <= M; j++) {
			int NextState = GetNext(i, j);
			G[i].push_back(NextState);
		}
	}

	// スタート地点・ゴール地点の頂点番号を求める
	int Goal = (1 << N) - 1;  // (1<<N) は「2 の N 乗」
	int Start = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] == 1) Start += (1 << (i - 1));
	}

	// 配列の初期化／スタート地点をキューに入れる
	queue<int> Q;
	for (int i = 0; i < (1 << N); i++) dist[i] = -1;
	dist[Start] = 0;
	Q.push(Start);

	// 幅優先探索
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int i = 0; i < G[pos].size(); i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q.push(nex);
			}
		}
	}

	// 答えを出力
	cout << dist[Goal] << endl;
	return 0;
}
