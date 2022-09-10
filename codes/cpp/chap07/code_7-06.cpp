#include <iostream>
using namespace std;

int N = 100;
int A[109][109];
int X[1009], Y[1009], H[1009];

int main() {
	// 入力
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}

	// 答えを生成
	for (int i = 1; i <= 1000; i++) {
		X[i] = rand() % N; // 0 以上 N-1 以下のランダムな整数
		Y[i] = rand() % N; // 0 以上 N-1 以下のランダムな整数
		H[i] = 1;
	}

	// 出力
	cout << "1000" << endl;
	for (int i = 1; i <= 1000; i++) {
		cout << X[i] << " " << Y[i] << " " << H[i] << endl;
	}
	return 0;
}
