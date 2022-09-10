#include <iostream>
using namespace std;

int main() {
	// 入力
	long long N, A[100009]; char T[100009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> T[i] >> A[i];

	// 出力（Answer は現在の黒板の数）
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (T[i] == '+') Answer += A[i];
		if (T[i] == '-') Answer -= A[i];
		if (T[i] == '*') Answer *= A[i];
		cout << Answer % 10000 << endl;
	}
	return 0;
}
