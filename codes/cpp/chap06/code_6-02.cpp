#include <iostream>
using namespace std;

int main() {
	// 入力
	int N, A[200009]; long long Answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 全探索（選ぶ棒の番号を小さい順に i, j, k とする）
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (A[i] == A[j] && A[j] == A[k]) Answer += 1;
			}
		}
	}
	cout << Answer << endl;
	return 0;
}
