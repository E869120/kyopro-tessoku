#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009], P[100009], Q[100009];
int D, L[100009], R[100009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> D;
	for (int d = 1; d <= D; d++) cin >> L[d] >> R[d];

	// P[i] を求める
	P[1] = A[1];
	for (int i = 2; i <= N; i++) P[i] = max(P[i - 1], A[i]);

	// Q[i] を求める
	Q[N] = A[N];
	for (int i = N - 1; i >= 1; i--) Q[i] = max(Q[i + 1], A[i]);

	// それぞれの日について答えを求める
	for (int d = 1; d <= D; d++) {
		cout << max(P[L[d] - 1], Q[R[d] + 1]) << endl;
	}
	return 0;
}
