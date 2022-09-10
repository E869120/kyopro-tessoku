#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int N, X[159], Y[159];
int P[159];

// a 以上 b 以下の整数をランダムに返す関数
int RandInt(int a, int b) {
	return a + rand() % (b - a + 1);
}

// 都市 p と q の間の距離を求める関数
double GetDistance(int p, int q) {
	return sqrt((X[p] - X[q]) * (X[p] - X[q]) + (Y[p] - Y[q]) * (Y[p] - Y[q]));
}

// スコアを計算する関数
double GetScore() {
	double sum = 0;
	for (int i = 1; i <= N; i++) sum += GetDistance(P[i], P[i + 1]);
	return sum;
}

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

	// 初期解生成
	P[1] = 1; P[N + 1] = 1;
	for (int i = 2; i <= N; i++) P[i] = i;

	// 山登り法
	double CurrentScore = GetScore();
	for (int t = 1; t <= 200000; t++) {
		// ランダムに反転させる区間 [L, R] を選ぶ
		int L = RandInt(2, N);
		int R = RandInt(2, N);
		if (L > R) swap(L, R);

		// reverse は配列の L ～ R 番目を反転させる関数
		reverse(P + L, P + R + 1);
		double NewScore = GetScore();

		// 改善すればスコアを更新、悪化すれば元に戻す
		if (CurrentScore >= NewScore) CurrentScore = NewScore;
		else reverse(P + L, P + R + 1);
	}

	// 出力
	for (int i = 1; i <= N + 1; i++) cout << P[i] << endl;
	return 0;
}
