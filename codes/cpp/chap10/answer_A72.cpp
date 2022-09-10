#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W, K;
int Answer = 0;
char c[19][109], d[19][109]; // 配列 d はマス目 D に対応

// 残り remaining_steps 回の「列に対する操作」で、最大何個のマスを黒くできるかを返す関数
int paintRow(int remaining_steps) {
	// 各列に対する「白マスの個数」を計算し、大きい順にソートする
	vector<pair<int, int>> Column;
	for (int j = 1; j <= W; j++) {
		int cnt = 0;
		for (int i = 1; i <= H; i++) {
			if (d[i][j] == '.') cnt += 1;
		}
		Column.push_back(make_pair(cnt, j));
	}
	sort(Column.begin(), Column.end());
	reverse(Column.begin(), Column.end());

	// 列に対して操作を行う
	for (int j = 0; j < remaining_steps; j++) {
		int idx = Column[j].second;
		for (int i = 1; i <= H; i++) d[i][idx] = '#';
	}

	// 黒マスの個数を数える
	int ret = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (d[i][j] == '#') ret += 1;
		}
	}
	return ret;
}

int main() {
	// 入力
	cin >> H >> W >> K;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}

	// ビット全探索
	for (int t = 0; t < (1 << H); t++) {
		// まずはマス目を初期盤面に設定
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) d[i][j] = c[i][j];
		}

		// 行に対して操作を行う
		// 変数 remaining_steps は残り操作回数
		int remaining_steps = K;
		for (int i = 1; i <= H; i++) {
			int wari = (1 << (i - 1));
			if ((t / wari) % 2 == 0) continue;
			remaining_steps -= 1;
			for (int j = 1; j <= W; j++) d[i][j] = '#'; // i 行目を黒く塗る
		}

		// 列に対して操作を行う
		if (remaining_steps >= 0) {
			int SubAnswer = paintRow(remaining_steps);
			Answer = max(Answer, SubAnswer);
		}
	}

	// 出力
	cout << Answer << endl;
	return 0;
}
