#include <iostream>
#include <algorithm>
using namespace std;

long long N, K;
double A[100009];

// 割り算の値が x であるときの議席数は？
long long check(double x) {
	long long sum = 0;
	for (int i = 1; i <= N; i++) sum += (long long)(A[i] / x);
	return sum;
}

int main() {
	// 入力
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 二分探索
	double Left = 1, Right = 1000000000, Mid;
	double Border = 0; // 現在のボーダー（合計議席数が K 以上となった最大の値）
	for (int i = 1; i <= 60; i++) {
		Mid = (Left + Right) / 2.0;

		// 割り算の値は Mid より大きいか？
		long long val = check(Mid);
		if (val >= K) {
			Left = Mid;
			Border = max(Border, Mid);
		}
		else {
			Right = Mid;
		}
	}

	// 出力
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << (long long)(A[i] / Border);
	}
	cout << endl;
	return 0;
}
