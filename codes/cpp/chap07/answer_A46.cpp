#include <iostream>
#include <cmath>
using namespace std;

int N, X[159], Y[159];
int P[159]; // 都市を訪れる順番の情報
bool visited[159]; // visited[i]=true のとき都市 i を訪問した

// 都市 p と q の間の距離を求める関数
double GetDistance(int p, int q) {
	return sqrt((X[p] - X[q]) * (X[p] - X[q]) + (Y[p] - Y[q]) * (Y[p] - Y[q]));
}

// 貪欲法によって答えを求める関数
void PlayGreedy() {
	// 配列の初期化
	int CurrentPlace = 1;
	for (int i = 1; i <= N; i++) visited[i] = false;
	P[1] = 1; visited[1] = true;

	// 貪欲法スタート
	for (int i = 2; i <= N; i++) {
		double MinDist = 10000.0; // 現時点での距離の最小
		int Min_ID = -1; // 次はどの都市に移動すれば良いか

		// 距離が最小となる都市を探す
		for (int j = 1; j <= N; j++) {
			if (visited[j] == true) continue;
			double NewDist = GetDistance(CurrentPlace, j);
			if (MinDist > NewDist) {
				MinDist = NewDist;
				Min_ID = j;
			}
		}

		// 現在位置の更新
		visited[Min_ID] = true;
		P[i] = Min_ID;
		CurrentPlace = Min_ID;
	}

	// 最後に訪問する都市
	P[N + 1] = 1;
}

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

	// 貪欲法
	PlayGreedy();

	// 出力
	for (int i = 1; i <= N + 1; i++) cout << P[i] << endl;
	return 0;
}
