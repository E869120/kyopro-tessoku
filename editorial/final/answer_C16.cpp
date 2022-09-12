#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 入力で与えられる変数
int N, M, K;
int A[100009], S[100009], B[100009], T[100009];

// 各空港の "時刻表"
vector<int> Time[100009];

// グラフ
vector<int> VertID[100009];        // 頂点番号（Time に対応）
vector<pair<int, int>> G[400009];  // グラフ
int Verts = 0;                     // グラフの頂点数

// 動的計画法
int dp[400009];

int main() {
	// 入力
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> S[i] >> B[i] >> T[i];
		T[i] += K; // 補正をかける
		Time[A[i]].push_back(S[i]);
		Time[B[i]].push_back(T[i]);
	}

	// Time[i] に「始点」と「終点」を追加した上でソートする
	for (int i = 1; i <= N; i++) {
		Time[i].push_back(0);
		Time[i].push_back(2000000000);
		sort(Time[i].begin(), Time[i].end());
	}

	// 動的計画法（Step 1：頂点を "時刻の小さい順" にソート）
	vector<pair<int, int>> tmp;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Time[i].size(); j++) tmp.push_back(make_pair(Time[i][j], i));
	}
	sort(tmp.begin(), tmp.end());
	Verts = tmp.size();

	// 動的計画法（Step 2：頂点番号を求める）
	for (int i = 0; i < Verts; i++) {
		VertID[tmp[i].second].push_back(i);
	}

	// 動的計画法（Step 3：グラフを作る [空港に留まる辺]）
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (int)VertID[i].size() - 1; j++) {
			G[VertID[i][j]].push_back(make_pair(VertID[i][j + 1], 0));
		}
	}

	// 動的計画法（Step 4：グラフを作る [飛行機で移動する辺]）
	for (int i = 1; i <= M; i++) {
		int pos1 = lower_bound(Time[A[i]].begin(), Time[A[i]].end(), S[i]) - Time[A[i]].begin();
		int pos2 = lower_bound(Time[B[i]].begin(), Time[B[i]].end(), T[i]) - Time[B[i]].begin();
		int vert1 = VertID[A[i]][pos1]; // 始点の頂点番号
		int vert2 = VertID[B[i]][pos2]; // 終点の頂点番号
		G[vert1].push_back(make_pair(vert2, 1));
	}

	// 動的計画法（Step 5：配列 dp の初期化 + 初期状態を考える）
	for (int i = 0; i < Verts; i++) dp[i] = -1000000000;
	for (int i = 1; i <= N; i++) {
		dp[VertID[i][0]] = 0;
	}

	// 動的計画法（Step 6：配列 dp の値を求める）
	for (int i = 0; i < Verts; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			int to = G[i][j].first;
			int cost = G[i][j].second;
			dp[to] = max(dp[to], dp[i] + cost);
		}
	}

	// 答えを求める
	int Answer = 0;
	for (int i = 0; i < Verts; i++) Answer = max(Answer, dp[i]);
	cout << Answer << endl;
	return 0;
}
