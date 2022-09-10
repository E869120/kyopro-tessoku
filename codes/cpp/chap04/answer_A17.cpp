#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int N, A[100009], B[100009], dp[100009];
vector<int> Answer;

int main() {
	// 入力
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> A[i];
	for (int i = 3; i <= N; i++) cin >> B[i];

	// 動的計画法
	dp[1] = 0;
	dp[2] = A[2];
	for (int i = 3; i <= N; i++) dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);

	// 答えの復元
	// 変数 Place は現在位置（ゴールから進んでいく）
	// たとえば入力例の場合、Place は 5 → 4 → 2 → 1 と変化していく
	int Place = N;
	while (true) {
		Answer.push_back(Place);
		if (Place == 1) break;

		// どこから部屋 Place に向かうのが最適かを求める
		if (dp[Place - 1] + A[Place] == dp[Place]) Place = Place - 1;
		else Place = Place - 2;
	}

	// 変数 Answer は「ゴールからの経路」になっているので、逆順にする
	// たとえば入力例の場合、Answer = {5, 4, 2, 1} を {1, 2, 4, 5} にする
	reverse(Answer.begin(), Answer.end());

	// 答えを出力
	cout << Answer.size() << endl;
	for (int i = 0; i < Answer.size(); i++) {
		if (i >= 1) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}
