#include <iostream>
using namespace std;

int N, A[100009], S[100009];
int Q, L[100009], R[100009];

int main() {
	// 入力
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int j = 1; j <= Q; j++) cin >> L[j] >> R[j];

	// 累積和の計算
	S[0] = 0;
	for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

	// 質問に答える
	for (int j = 1; j <= Q; j++) {
		cout << S[R[j]] - S[L[j] - 1] << endl;
	}
	return 0;
}
