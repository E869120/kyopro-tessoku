#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 盤面の状態を表す構造体
struct State {
	int score; // 暫定スコア
	int X[29]; // 現在の配列 X の値
	char LastMove; // 最後の動き（'A' または 'B'）
	int LastPos; // Beam[i-1][ どこ ] から遷移したか
};

// sort 関数の順序を決める（スコアが大きい方が「大きい」とする）
bool operator>(const State& a1, const State& a2) {
	if (a1.score > a2.score) return true;
	else return false;
}

// 必要な変数・配列（WIDTH はビーム幅、NumState[i] は i 手目時点での状態数）
const int WIDTH = 10000;
const int N = 20;
int T, P[109], Q[109], R[109];
int NumState[109];
State Beam[109][WIDTH];
char Answer[109];

// ビームサーチを行う関数
void BeamSearch() {
	// 0 手目の状態を設定
	NumState[0] = 1;
	Beam[0][0].score = 0;
	for (int i = 1; i <= N; i++) Beam[0][0].X[i] = 0;

	// ビームサーチ
	for (int i = 1; i <= T; i++) {
		vector<State> Candidate;
		for (int j = 0; j < NumState[i - 1]; j++) {
			// 操作 A の場合
			State SousaA = Beam[i - 1][j];
			SousaA.LastMove = 'A';
			SousaA.LastPos = j;
			SousaA.X[P[i]] += 1;
			SousaA.X[Q[i]] += 1;
			SousaA.X[R[i]] += 1;
			for (int k = 1; k <= N; k++) {
				if (SousaA.X[k] == 0) SousaA.score += 1;
			}

			// 操作 B の場合
			State SousaB = Beam[i - 1][j];
			SousaB.LastMove = 'B';
			SousaB.LastPos = j;
			SousaB.X[P[i]] -= 1;
			SousaB.X[Q[i]] -= 1;
			SousaB.X[R[i]] -= 1;
			for (int k = 1; k <= N; k++) {
				if (SousaB.X[k] == 0) SousaB.score += 1;
			}

			// 候補に追加
			Candidate.push_back(SousaA);
			Candidate.push_back(SousaB);
		}

		// ソートして Beam[i] の結果を計算する
		sort(Candidate.begin(), Candidate.end(), greater<State>());
		NumState[i] = min(WIDTH, (int)Candidate.size());
		for (int j = 0; j < NumState[i]; j++) Beam[i][j] = Candidate[j];
	}
}

int main() {
	// 入力
	cin >> T;
	for (int i = 1; i <= T; i++) cin >> P[i] >> Q[i] >> R[i];

	// ビームサーチ
	BeamSearch();

	// ビームサーチの復元（CurrentPlace は配列 Beam のどの位置を見ているかを表す）
	int CurrentPlace = 0;
	for (int i = T; i >= 1; i--) {
		Answer[i] = Beam[i][CurrentPlace].LastMove;
		CurrentPlace = Beam[i][CurrentPlace].LastPos;
	}

	// 出力
	for (int i = 1; i <= T; i++) cout << Answer[i] << endl;
	return 0;
}
