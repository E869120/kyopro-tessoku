#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int A[309], B[309];

// 整数の組 (a, b) が決まったときの、参加可能な生徒数を返す関数
int GetScore(int a, int b) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (a <= A[i] && A[i] <= a + K && b <= B[i] && B[i] <= b + K) {
			cnt += 1;
		}
	}
	return cnt;
}

int main() {
	// 入力
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

	// (a, b) の組を全探索
	int Answer = 0;
	for (int a = 1; a <= 100; a++) {
		for (int b = 1; b <= 100; b++) {
			int Score = GetScore(a, b);
			Answer = max(Answer, Score);
		}
	}

	// 出力
	cout << Answer << endl;
	return 0;
}
