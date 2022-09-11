#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 入力
int H, W;
int sx, sy, start; // スタートの座標 (sx, sy) と頂点番号 sx*H+sy
int gx, gy, goal;  // ゴールの座標 (gx, gy) と頂点番号 gx*W+gy
char c[59][59];

// グラフ・最短経路
int dist[2509];
vector<int> G[2509];

int main() {
	// 入力
	cin >> H >> W;
	cin >> sx >> sy; start = sx * W + sy;
	cin >> gx >> gy; goal = gx * W + gy;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}

	// 横方向の辺 [(i, j) - (i, j+1)] をグラフに追加
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W - 1; j++) {
			int idx1 = i * W + j; // 頂点 (i, j) の頂点番号
			int idx2 = i * W + (j + 1); // 頂点 (i, j+1) の頂点番号
			if (c[i][j] == '.' && c[i][j + 1] == '.') {
				G[idx1].push_back(idx2);
				G[idx2].push_back(idx1);
			}
		}
	}

	// 縦方向の辺 [(i, j) - (i+1, j)] をグラフに追加
	for (int i = 1; i <= H - 1; i++) {
		for (int j = 1; j <= W; j++) {
			int idx1 = i * W + j; // 頂点 (i, j) の頂点番号
			int idx2 = (i + 1) * W + j; // 頂点 (i+1, j) の頂点番号
			if (c[i][j] == '.' && c[i + 1][j] == '.') {
				G[idx1].push_back(idx2);
				G[idx2].push_back(idx1);
			}
		}
	}

	// 幅優先探索の初期化
	for (int i = 1; i <= H * W; i++) dist[i] = -1;
	queue<int> Q;
	Q.push(start); dist[start] = 0;

	// 幅優先探索
	while (!Q.empty()) {
		int pos = Q.front();
		Q.pop();
		for (int i = 0; i < G[pos].size(); i++) {
			int to = G[pos][i];
			if (dist[to] == -1) {
				dist[to] = dist[pos] + 1;
				Q.push(to);
			}
		}
	}

	// 答えを出力
	cout << dist[goal] << endl;
	return 0;
}
