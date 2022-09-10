#include <iostream>
#include <algorithm>
using namespace std;

int N, A[69], B[69];
int Answer = 0;

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];

	// 配列のソート（reverse 関数は配列を逆順にする関数）
	sort(A + 1, A + N + 1);
	sort(B + 1, B + N + 1); reverse(B + 1, B + N + 1);

	// 答えを求める
	for (int i = 1; i <= N; i++) Answer += A[i] * B[i];
	cout << Answer << endl;
	return 0;
}
