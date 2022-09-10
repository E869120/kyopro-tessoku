#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// 入力
	int N, A[100009], B[100009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 配列 T の作成
	vector<int> T;
	for (int i = 1; i <= N; i++) T.push_back(A[i]);
	sort(T.begin(), T.end());

	// 配列 T の重複を消す
	// erase 関数・unique 関数は本書の範囲外ですが、ぜひ調べておきましょう
	T.erase(unique(T.begin(), T.end()), T.end());

	// 答えを求める
	for (int i = 1; i <= N; i++) {
		// vector 型の lower_bound は以下のような形式で書く
		// vector 型の添字は 0 番目から始まるので、1 を足す必要があることに注意
		B[i] = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
		B[i] += 1;
	}

	// 答えを空白区切りで出力
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << B[i];
	}
	cout << endl;
	return 0;
}
