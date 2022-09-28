#include <iostream>
#include <deque>
#include <string>
using namespace std;

// 入力で与えられる変数
int Q;
char QueryType[300009]; string X[300009];

// デック
deque<string> Z1, Z2;

int main() {
	// 入力
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> QueryType[i];
		if (QueryType[i] == 'A' || QueryType[i] == 'B') cin >> X[i];
	}

	// クエリの処理
	for (int i = 1; i <= Q; i++) {
		// [A] 最後尾に入る
		if (QueryType[i] == 'A') {
			Z2.push_back(X[i]);
		}
		// [B] 中央に入る
		if (QueryType[i] == 'B') {
			Z1.push_back(X[i]);
		}
		// [C] 先頭が抜ける
		if (QueryType[i] == 'C') {
			Z1.pop_front();
		}
		// [D] 先頭を答える
		if (QueryType[i] == 'D') {
			cout << Z1.front() << endl;
		}

		// 微調整（前半のデック Z1 が大きすぎる場合）
		while ((int)Z1.size() - (int)Z2.size() >= 2) {
			string r = Z1.back();
			Z1.pop_back();
			Z2.push_front(r);
		}
		// 微調整（後半のデック Z2 が大きすぎる場合）
		while ((int)Z1.size() - (int)Z2.size() <= -1) {
			string r = Z2.front();
			Z2.pop_front();
			Z1.push_back(r);
		}
	}
	return 0;
}
