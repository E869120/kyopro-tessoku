#include <iostream>
using namespace std;

// 配列 dp について： dp[x]=true のとき勝ちの状態、dp[x]=false のとき負けの状態
int N, K, A[109];
bool dp[100009];

int main() {
	// 入力
	cin >> N >> K;
	for (int i = 1; i <= K; i++) cin >> A[i];

	// 勝者を計算する
	for (int i = 0; i <= N; i++) {
		dp[i] = false;
		for (int j = 1; j <= K; j++) {
			if (i >= A[j] && dp[i - A[j]] == false) {
				dp[i] = true; // 負けの状態に遷移できれば、勝ちの状態
			}
		}
	}

	// 出力
	if (dp[N] == true) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
