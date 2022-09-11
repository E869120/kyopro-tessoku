#include <iostream>
using namespace std;
 
// 入力で与えられる変数など
int N, Q, L[100009], R[100009], T[100009];
string S;
 
// ハッシュ値など
long long mod = 2147483647;
long long Power100[100009];
long long H_Left[100009];  // 左からのハッシュ
long long H_Right[100009]; // 右からのハッシュ

// 文字列の l~r 番目を左から読んだ時のハッシュ値を返す関数
long long GetHashLeft(int l, int r) {
	long long val = H_Left[r] - (Power100[r - l + 1] * H_Left[l - 1] % mod);
	if (val < 0) val += mod;
	return val;
}

// 文字列の l~r 番目を右から読んだ時のハッシュ値を返す関数
long long GetHashRight(int l, int r) {
	long long val = H_Right[l] - (Power100[r - l + 1] * H_Right[r + 1] % mod);
	if (val < 0) val += mod;
	return val;
}
 
int main() {
	// 入力
	cin >> N >> Q;
	cin >> S;
	for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];
 
	// 文字を数値に変換
	for (int i = 1; i <= N; i++) T[i] = (int)(S[i - 1] - 'a') + 1;
 
	// 100 の n 乗
	Power100[0] = 1;
	for (int i = 1; i <= N; i++) Power100[i] = (100LL * Power100[i - 1]) % mod;
 
	// ハッシュ値の計算（左から）
	H_Left[0] = 1;
	for (int i = 1; i <= N; i++) H_Left[i] = (100LL * H_Left[i - 1] + T[i]) % mod;
 
	// ハッシュ値の計算（右から）
	H_Right[N + 1] = 1;
	for (int i = N; i >= 1; i--) H_Right[i] = (100LL * H_Right[i + 1] + T[i]) % mod;
 
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
