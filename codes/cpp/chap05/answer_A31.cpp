#include <iostream>
using namespace std;

// 配列 dp について： dp[x]=true のとき勝ちの状態、dp[x]=false のとき負けの状態
int N, A, B;
bool dp[100009];

int main() {
	// 入力
	cin >> N >> A >> B;

	// 勝者を計算する
	for (int i = 0; i <= N; i++) {
		if (i >= A && dp[i - A] == false) dp[i] = true; // 勝ちの状態
		else if (i >= B && dp[i - B] == false) dp[i] = true; // 勝ちの状態
		else dp[i] = false; // 負けの状態
	}

	// 出力
	if (dp[N] == true) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
