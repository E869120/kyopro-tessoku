#include <iostream>
#include <map>
using namespace std;
 
int N, A[100009];
map<int, int> Map;
 
int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// 答えを求める
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		Answer += Map[A[i]];
		Map[A[i]] += 1;
	}
 
	// 出力
	cout << Answer << endl;
	return 0;
}
