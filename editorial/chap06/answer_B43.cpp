#include <iostream>
using namespace std;
 
int N, M;
int A[200009];
int Incorrect[200009];
 
int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i];
 
	// 不正解数を求める
	for (int i = 1; i <= N; i++) Incorrect[i] = 0;
	for (int i = 1; i <= M; i++) Incorrect[A[i]] += 1;
 
	// 答えを出力
	for (int i = 1; i <= N; i++) cout << M - Incorrect[i] << endl;
	return 0;
}
