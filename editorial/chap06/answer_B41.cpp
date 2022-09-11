#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int X, Y;
 
int main() {
	// 入力
	cin >> X >> Y;
 
	// 逆から考えていく
	vector<pair<int, int>> Answer;
	while (X >= 2 || Y >= 2) {
		Answer.push_back(make_pair(X, Y));
		if (X > Y) X -= Y;
		else Y -= X;
	}
	reverse(Answer.begin(), Answer.end());
 
	// 出力
	cout << Answer.size() << endl;
	for (int i = 0; i < Answer.size(); i++) {
		cout << Answer[i].first << " " << Answer[i].second << endl;
	}
	return 0;
}
