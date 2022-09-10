#include <iostream>
using namespace std;

int N, L, K, A[100009];

bool check(int x) {
	int Count = 0, Last_Kireme = 0;// Count は現時点で何回切ったかを表す
	for (int i = 1; i <= N; i++) {
		if (A[i] - Last_Kireme >= x && L - A[i] >= x) {
			Count += 1;
			Last_Kireme = A[i];
		}
	}
	if (Count >= K) return true;
	return false;
}

int main() {
	// 入力
	cin >> N >> L >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 二分探索（left: 現在の下限／ right: 現在の上限）
	long long left = 1, right = 1'000'000'000;
	while (left < right) {
		long long mid = (left + right + 1) / 2;
		bool Answer = check(mid);
		if (Answer == false) right = mid - 1; // 答えが前半部分に絞られる
		if (Answer == true) left = mid; // 答えが後半部分に絞られる
	}

	// 出力
	cout << left << endl;
	return 0;
}
