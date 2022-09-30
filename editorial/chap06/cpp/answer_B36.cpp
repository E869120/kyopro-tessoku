#include <iostream>
#include <string>
using namespace std;
 
int N, K;
string S;
 
int main() {
	// 入力
	cin >> N >> K;
	cin >> S;
 
	// ON となっているものの個数を数える
	int numON = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') numON += 1;
	}
 
	// 答えを出力
	if (numON % 2 == K % 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
