#include <iostream>
using namespace std;
 
int N, A[509][509];
int Q, QueryType[200009], x[200009], y[200009];
int T[509];
 
int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> A[i][j];
	}
 
	// 配列 T を初期化
	for (int i = 1; i <= N; i++) T[i] = i;
 
	// クエリの処理
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> QueryType[i] >> x[i] >> y[i];
		if (QueryType[i] == 1) {
			swap(T[x[i]], T[y[i]]);
		}
		if (QueryType[i] == 2) {
			cout << A[T[x[i]]][y[i]] << endl;
		}
	}
	return 0;
}
