#include <iostream>
#include <stack>
using namespace std;
 
int main() {
	// 入力
	string S;
	cin >> S;
 
	// 左から順番に見ていく
	// 文字列は 0 文字目から始まることに注意
	stack<int> Stack;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') {
			Stack.push(i + 1);
		}
		if (S[i] == ')') {
			cout << Stack.top() << " " << i + 1 << endl;
			Stack.pop();
		}
	}
	return 0;
}
