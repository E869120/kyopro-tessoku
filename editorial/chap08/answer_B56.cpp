#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 入力で与えられる変数など
int N, Q, L[100009], R[100009];
string S;
string SRev; // S の逆順

// 文字列を数値に変換した値（それぞれ S, SRev に対応）
int T[100009];
int TRev[100009];

// ハッシュ値など
long long mod = 2147483647;
long long Power100[100009];
long long H[100009];    // S のハッシュ
long long HRev[100009]; // SRev のハッシュ

// 文字列の l～r 番目を前から読んだ時のハッシュ値を返す関数
long long GetHashLeft(int l, int r) {
	long long val = H[r] - (Power100[r - l + 1] * H[l - 1] % mod);
	if (val < 0) val += mod;
	return val;
}

// 文字列の l～r 番目を後ろから読んだ時のハッシュ値を返す関数
long long GetHashRight(int l, int r) {
	int true_l = N + 1 - r;
	int true_r = N + 1 - l;
	long long val = HRev[true_r] - (Power100[true_r - true_l + 1] * HRev[true_l - 1] % mod);
	if (val < 0) val += mod;
	return val;
}

int main() {
	// 入力
	cin >> N >> Q;
	cin >> S;
	for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];
	SRev = S;
	reverse(SRev.begin(), SRev.end());

	// S, SRev の文字を数値に変換
	for (int i = 1; i <= N; i++) T[i] = (int)(S[i - 1] - 'a') + 1;
	for (int i = 1; i <= N; i++) TRev[i] = (int)(SRev[i - 1] - 'a') + 1;

	// 100 の n 乗を前計算
	Power100[0] = 1;
	for (int i = 1; i <= N; i++) Power100[i] = (100LL * Power100[i - 1]) % mod;

	// S のハッシュ値を前計算
	H[0] = 1;
	for (int i = 1; i <= N; i++) H[i] = (100LL * H[i - 1] + T[i]) % mod;

	// SRev のハッシュ値を前計算
	HRev[0] = 1;
	for (int i = 1; i <= N; i++) HRev[i] = (100LL * HRev[i - 1] + TRev[i]) % mod;

	// クエリの処理
	for (int i = 1; i <= Q; i++) {
		long long v1 = GetHashLeft(L[i], R[i]);
		long long v2 = GetHashRight(L[i], R[i]);
		// 左から読んだ時・右から読んだ時のハッシュ値が一致していれば回文
		if (v1 == v2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
