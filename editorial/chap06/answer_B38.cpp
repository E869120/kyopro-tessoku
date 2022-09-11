#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int N, ret1[1 << 18], ret2[1 << 18];
string S;
 
int main() {
	// 入力
	cin >> N >> S;
 
	// 答えを求める
	int streak1 = 1; ret1[0] = 1; // streak1 は「何個 A が連続したか」+ 1
	for (int i = 0; i < N - 1; i++) {
		if (S[i] == 'A') streak1 += 1;
		if (S[i] == 'B') streak1 = 1;
		ret1[i + 1] = streak1;
	}
	int streak2 = 1; ret2[N - 1] = 1; // streak2 は「何個 B が連続したか」+ 1
	for (int i = N - 2; i >= 0; i--) {
		if (S[i] == 'B') streak2 += 1;
		if (S[i] == 'A') streak2 = 1;
		ret2[i] = streak2;
	}
 
	// 出力
	long long Answer = 0;
	for (int i = 0; i < N; i++) Answer += max(ret1[i], ret2[i]);
	cout << Answer << endl;
	return 0;
}
