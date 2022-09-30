#include <iostream>
using namespace std;
 
int main() {
	// 入力
	int N, A[109];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 答えを求める
	bool Answer = false;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (A[i] + A[j] + A[k] == 1000) Answer = true;
			}
		}
	}
	
	// 出力
	if (Answer == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
