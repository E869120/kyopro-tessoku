#include <iostream>
#include <algorithm>
using namespace std;

long long N, C[100009], S[100009];
long long Q, X[100009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i];
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> X[i];

	// C[i] を小さい順にソート
	sort(C + 1, C + N + 1);

	// 累積和 S[i] をとる
	// S[i] は「i 個の品物を買うときの最小金額」
	S[0] = 0;
	for (int i = 1; i <= N; i++) S[i] = S[i - 1] + C[i];

	// 質問に答える
	for (int i = 1; i <= Q; i++) {
		int pos = upper_bound(S, S + N + 1, X[i]) - S;
		cout << pos - 1 << endl;
	}
	return 0;
}
