#include <iostream>
using namespace std;
 
int N, D;
int X[2009], Y[2009];
bool used[2009]; // used[i] は仕事 i を選んだかどうか
int Answer = 0;
 
int main() {
	// 入力
	cin >> N >> D;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
 
	// 答えを求める
	for (int i = 1; i <= D; i++) {
		int maxValue = 0; // 給料の最大値
		int maxID = -1;   // 給料が最大となる仕事の番号
		for (int j = 1; j <= N; j++) {
			if (used[j] == true) continue;
			if (maxValue < Y[j] && X[j] <= i) {
				maxValue = Y[j];
				maxID = j;
			}
		}
 
		// 選べる仕事がある場合
		if (maxID != -1) {
			Answer += maxValue;
			used[maxID] = true;
		}
	}
 
	// 出力
	cout << Answer << endl;
	return 0;
}
