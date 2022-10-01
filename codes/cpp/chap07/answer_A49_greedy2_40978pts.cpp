// ###############################################
// # 本の 272 ページ後半の評価関数を用いた実装です
// ###############################################

#include <iostream>
#include <cmath>
using namespace std;

int T, P[109], Q[109], R[109];
int A[109];
int PatA[109], PatB[109];

int main() {
	// 入力
	cin >> T;
	for (int i = 1; i <= T; i++) cin >> P[i] >> Q[i] >> R[i];

	// 配列 A の初期化
	for (int i = 1; i <= 20; i++) A[i] = 0;

	// 貪欲法
	for (int i = 1; i <= T; i++) {
		// パターン A の場合のスコアを求める
		int ScoreA = 0;
		for (int j = 1; j <= 20; j++) PatA[j] = A[j];
		PatA[P[i]] += 1;
		PatA[Q[i]] += 1;
		PatA[R[i]] += 1;
		for (int j = 1; j <= 20; j++) ScoreA += abs(PatA[j]);

		// パターン B の場合のスコアを求める
		int ScoreB = 0;
		for (int j = 1; j <= 20; j++) PatB[j] = A[j];
		PatB[P[i]] -= 1;
		PatB[Q[i]] -= 1;
		PatB[R[i]] -= 1;
		for (int j = 1; j <= 20; j++)  ScoreB += abs(PatB[j]);

		// スコアの小さい方を採用
		if (ScoreA <= ScoreB) {
			cout << "A" << endl;
			for (int j = 1; j <= 20; j++) A[j] = PatA[j];
		}
		else {
			cout << "B" << endl;
			for (int j = 1; j <= 20; j++) A[j] = PatB[j];
		}
	}
	return 0;
}
