#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N, X[100009], Y[100009];
int LEN, L[100009];
 
// 配列 A の最長増加部分列（LIS）の長さを計算する
// 配列 dp を使わない実装方法を利用している
int Get_LISvalue(vector<int> A) {
	LEN = 0;
	for (int i = 1; i <= A.size(); i++) L[i] = 0;
 
	// 動的計画法
	for (int i = 0; i < A.size(); i++) {
		int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
		L[pos] = A[i];
		if (pos > LEN) LEN += 1;
	}
	return LEN;
}
 
int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
 
	// ソート
	vector<pair<int, int>> tmp;
	for (int i = 1; i <= N; i++) tmp.push_back(make_pair(X[i], -Y[i]));
	sort(tmp.begin(), tmp.end());
	
	// LIS を求めるべき配列は？
	vector<int> A;
	for (int i = 0; i < tmp.size(); i++) {
		A.push_back(-tmp[i].second);
	}
 
	// 出力
	cout << Get_LISvalue(A) << endl;
	return 0;
}
