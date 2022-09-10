#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; char c[159][159];
MaximumFlow Z; // MaximumFlow クラスは 9.8 節参照

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> c[i][j];
	}

	// グラフを構成する
	Z.init(2 * N + 2);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (c[i][j] == '#') Z.add_edge(i, N + j, 1);
		}
	}
	for (int i = 1; i <= N; i++) {
		Z.add_edge(2 * N + 1, i, 1); // 「s → 青色」の辺
		Z.add_edge(N + i, 2 * N + 2, 1); // 「赤色 → t」の辺
	}
	// 答えの出力
	cout << Z.max_flow(2 * N + 1, 2 * N + 2) << endl;
	return 0;
}
