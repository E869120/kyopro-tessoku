#include <iostream>
#include <string>
using namespace std;
 
long long N;
long long R[18][10]; // R[i][j] は「下から i 桁目が j となるような N 以下の整数の個数」
long long Power10[18];
 
int main() {
	// 入力
	cin >> N;
 
	// 10 の N 乗を求める
	Power10[0] = 1;
	for (int i = 1; i <= 16; i++) Power10[i] = 10LL * Power10[i - 1];
 
	// R[i][j] の値を計算
	for (int i = 0; i <= 15; i++) {
		// 下から i 桁目の数字を求める
		long long Digit = (N / Power10[i]) % 10LL;
 
		// R[i][j] の値を求める
		for (int j = 0; j < 10; j++) {
			if (j < Digit) {
				R[i][j] = (N / Power10[i + 1] + 1LL) * Power10[i];
			}
			if (j == Digit) {
				R[i][j] = (N / Power10[i + 1]) * Power10[i] + (N % Power10[i]) + 1LL;
			}
			if (j > Digit) {
				R[i][j] = (N / Power10[i + 1]) * Power10[i];
			}
		}
	}
 
	// 答えを求める
	long long Answer = 0;
	for (int i = 0; i <= 15; i++) {
		for (int j = 0; j < 10; j++) Answer += 1LL * j * R[i][j];
	}
 
	// 出力
	cout << Answer << endl;
	return 0;
}
