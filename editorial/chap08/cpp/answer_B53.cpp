#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long N, D;
long long X[200009], Y[200009];
vector<long long> G[375]; // G[i] は i 日目から始まる仕事の給料のリスト
long long Answer = 0;

int main() {
	// 入力
	cin >> N >> D;
	for (int i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i];
		G[X[i]].push_back(Y[i]);
	}

	// 答えを求める
	priority_queue<long long> Q;
	for (int i = 1; i <= D; i++) {
		// i 日目から始まる仕事をキューに追加
		for (int j : G[i]) Q.push(j);

		// やる仕事を選択し、その仕事をキューから削除する
		if (!Q.empty()) {
			Answer += Q.top();
			Q.pop();
		}
	}

	// 出力
	cout << Answer << endl;
	return 0;
}
