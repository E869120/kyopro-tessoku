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
 
int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i];
		G[A[i]].push_back(make_pair(B[i], C[i]));
		G[B[i]].push_back(make_pair(A[i], C[i]));
	}
 
	// 配列の初期化
	for (int i = 1; i <= N; i++) kakutei[i] = false;
	for (int i = 1; i <= N; i++) cur[i] = 2000000000;
 
	// スタート地点をキューに追加
	cur[1] = 0;
	Q.push(make_pair(cur[1], 1));
 
	// ダイクストラ法
	while (!Q.empty()) {
		// 次に確定させるべき頂点を求める
		int pos = Q.top().second; Q.pop();
 
		// Q の最小要素が「既に確定した頂点」の場合
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
 
	// 答えの復元（Place は現在の位置：ゴールから出発）
	vector<int> Answer;
	int Place = N;
	while (true) {
		Answer.push_back(Place);
		if (Place == 1) break;
 
		// Place の前の頂点としては、一体どこが良いのか？
		for (int i = 0; i < G[Place].size(); i++) {
			int nex = G[Place][i].first;
			int cost = G[Place][i].second;
			if (cur[nex] + cost == cur[Place]) {
				Place = nex;
				break;
			}
		}
	}
	reverse(Answer.begin(), Answer.end());
 
	// 出力
	for (int i = 0; i < Answer.size(); i++) {
		if (i >= 1) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}
