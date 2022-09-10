#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// 入力
	int N, A[100009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 配列のソート
	// ここで、関数 sort(A+L, A+R) では A[L] から A[R-1] までの部分をソートする
	sort(A + 1, A + N + 1);

	// 出力
	for (int i = 1; i <= N; i++) cout << A[i] << endl;
	return 0;
}
