#include <iostream>
#include <algorithm>
using namespace std;
 
long long N;
long long A[100009], B[100009];
 
// omote=1 のとき表の総和が正、ura=1 のとき裏の総和が正
// omote=2 のとき表の総和が負、ura=2 のとき裏の総和が負
long long solve(int omote, int ura) {
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		long long card1 = A[i]; if (omote == 2) card1 = -A[i];
		long long card2 = B[i]; if (ura == 2) card2 = -B[i];
		// カード i は選ぶべきか？
		if (card1 + card2 >= 0) {
			sum += (card1 + card2);
		}
	}
	return sum;
}
 
int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
 
	// 表の総和の正負と、裏の総和の正負を全探索
	long long Answer1 = solve(1, 1);
	long long Answer2 = solve(1, 2);
	long long Answer3 = solve(2, 1);
	long long Answer4 = solve(2, 2);
 
	// 答えを出力
	cout << max({ Answer1,Answer2,Answer3,Answer4 }) << endl;
	return 0;
}
