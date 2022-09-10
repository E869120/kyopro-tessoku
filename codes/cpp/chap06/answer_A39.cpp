#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L[300009], R[300009];
vector<pair<int, int>> tmp; // 映画をソートするための一時変数

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i] >> R[i];
		tmp.push_back(make_pair(R[i], L[i]));
	}

	// R の小さい順にソート
	sort(tmp.begin(), tmp.end());
	for (int i = 1; i <= N; i++) {
		R[i] = tmp[i - 1].first;
		L[i] = tmp[i - 1].second;
	}

	// 終了時刻の早いものから貪欲に取っていく（CurrentTime は現在時刻）
	int CurrentTime = 0, Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (CurrentTime <= L[i]) {
			CurrentTime = R[i];
			Answer += 1;
		}
	}
	cout << Answer << endl;
	return 0;
}
