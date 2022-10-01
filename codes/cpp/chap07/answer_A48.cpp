#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int N, X[159], Y[159];
int P[159];

// 0 以上 1 以下のランダムな実数を返す関数
double Randouble() {
	return 1.0 * rand() / RAND_MAX;
}

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

	// 初期解生成
	P[1] = 1; P[N + 1] = 1;
	for (int i = 2; i <= N; i++) P[i] = i;

	// 焼きなまし法（GetScore 関数、RandInt 関数は 7.2 節を参照）
	double CurrentScore = GetScore();
	for (int t = 1; t <= 200000; t++) {
		int L = RandInt(2, N);
		int R = RandInt(2, N);
		if (L > R) swap(L, R);
		reverse(P + L, P + R + 1);
		double NewScore = GetScore();

		// 7.2 節の解答例から変更した唯一の部分（Probability は採用確率）
		double T = 30.00 - 28.00 * t / 200000.0;
		double Probability = exp(min(0.0, (CurrentScore - NewScore) / T));
		if (Randouble() < Probability) CurrentScore = NewScore;
		else reverse(P + L, P + R + 1);
	}

	// 出力
	for (int i = 1; i <= N + 1; i++) cout << P[i] << endl;
	return 0;
}
