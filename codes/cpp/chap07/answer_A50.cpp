#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int N = 100;
int Q = 1000;
int A[109][109], B[109][109];
int X[1009], Y[1009], H[1009];

// L 以上 R 以下のランダムな整数を返す関数
int RandInt(int L, int R) {
	return rand() % (R - L + 1) + L;
}

// 現在のスコアを返す関数
int GetScore() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) sum += abs(A[i][j] - B[i][j]);
	}
	return 200000000 - sum;
}

// X[t]=x, Y[t]=y, H[t]=h に変更する関数
void Change(int t, int x, int y, int h) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			B[j][i] -= max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
		}
	}
	X[t] = x;
	Y[t] = y;
	H[t] = h;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			B[j][i] += max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
		}
	}
}

void Yamanobori() {
	// 変数の設定（5.95 秒ループを回す）
	int TIMELIMIT = 5.95 * CLOCKS_PER_SEC;
	int CurrentScore = GetScore();
	int ti = clock();

	// 山登り法スタート
	while (clock() - ti < TIMELIMIT) {
		int t = RandInt(1, Q);
		int old_x = X[t], new_x = X[t] + RandInt(-9, 9);
		int old_y = Y[t], new_y = Y[t] + RandInt(-9, 9);
		int old_h = H[t], new_h = H[t] + RandInt(-19, 19);
		if (new_x < 0 || new_x >= N) continue;
		if (new_y < 0 || new_y >= N) continue;
		if (new_h <= 0 || new_h > N) continue;

		// とりあえず変更し、スコアを評価する
		Change(t, new_x, new_y, new_h);
		int NewScore = GetScore();

		// スコアに応じて採用／不採用を決める
		if (CurrentScore < NewScore) CurrentScore = NewScore;
		else Change(t, old_x, old_y, old_h);
	}
}

int main() {
	// 入力
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}

	// 初期解を生成
	for (int i = 1; i <= 1000; i++) {
		X[i] = rand() % N; // 0 以上 N-1 以下のランダムな整数
		Y[i] = rand() % N; // 0 以上 N-1 以下のランダムな整数
		H[i] = 1;
		B[X[i]][Y[i]] += 1;
	}

	// 山登り法
	Yamanobori();

	// 出力
	cout << "1000" << endl;
	for (int i = 1; i <= 1000; i++) {
		cout << X[i] << " " << Y[i] << " " << H[i] << endl;
	}
	return 0;
}
