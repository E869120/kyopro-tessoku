#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N, S, A[69];
bool dp[69][10009];
vector<int> Answer;
 
int main() {
	// 入力
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// 動的計画法 (i = 0)
	dp[0][0] = true;
	for (int i = 1; i <= S; i++) dp[0][i] = false;
 
	// 動的計画法 (i >= 1)
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			if (j < A[i]) {
				if (dp[i - 1][j] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
			if (j >= A[i]) {
				if (dp[i - 1][j] == true || dp[i - 1][j - A[i]] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
	}
 
	// 選び方が存在しない場合
	if (dp[N][S] == false) {
		cout << "-1" << endl;
		return 0;
	}
 
	// 答えの復元（Place は "現在の総和"）
	int Place = S;
	for (int i = N; i >= 1; i--) {
		if (dp[i - 1][Place] == true) {
			Place = Place - 0; // カード i を選ばない
		}
		else {
			Place = Place - A[i]; // カード i を選ぶ
			Answer.push_back(i);
		}
	}
	reverse(Answer.begin(), Answer.end());
 
	// 出力
	cout << Answer.size() << endl;
	for (int i = 0; i < Answer.size(); i++) {
		if (i >= 1) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}
