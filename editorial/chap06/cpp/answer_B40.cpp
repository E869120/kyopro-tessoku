#include <iostream>
using namespace std;
 
long long N, A[200009];
long long cnt[109];
long long Answer = 0;
 
int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// 個数を数える
	for (int i = 0; i < 100; i++) cnt[i] = 0;
	for (int i = 1; i <= N; i++) cnt[A[i] % 100] += 1;
 
	// 答えを求める
	for (int i = 1; i < 50; i++) Answer += cnt[i] * cnt[100 - i];
	Answer += cnt[0] * (cnt[0] - 1LL) / 2LL;
	Answer += cnt[50] * (cnt[50] - 1LL) / 2LL;
 
	// 出力
	cout << Answer << endl;
	return 0;
}
