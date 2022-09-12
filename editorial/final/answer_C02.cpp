#include <iostream>
#include <algorithm>
using namespace std;

int N, A[109];
int Answer = 0;

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 答えを求める（全探索）
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) Answer = max(Answer, A[i] + A[j]);
	}

	// 出力
	cout << Answer << endl;
	return 0;
}
