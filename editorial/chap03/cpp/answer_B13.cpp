#include <iostream>
using namespace std;
 
long long N, K;
long long A[100009];
long long S[100009]; // 累積和
long long R[100009]; // 左端が決まったとき、右端はどこまで行けるか
 
// A[l] から A[r] までの合計値
long long sum(int l, int r) {
	return S[r] - S[l - 1];
}
 
int main() {
	// 入力
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// 累積和をとる
	S[0] = 0;
	for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
 
	// しゃくとり法
	for (int i = 1; i <= N; i++) {
		if (i == 1) R[i] = 0;
		else R[i] = R[i - 1];
		while (R[i] < N && sum(i, R[i] + 1) <= K) {
			R[i] += 1;
		}
	}
	
	// 答えを求める
	long long Answer = 0;
	for (int i = 1; i <= N; i++) Answer += (R[i] - i + 1);
	cout << Answer << endl;
	return 0;
}
