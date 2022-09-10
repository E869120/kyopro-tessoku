// スコアの最大値が 12 以上かどうかを判定したい場合、check(12) を呼び出せばよい
bool check(int x) {
	int Count = 0, Last_Kireme = 0; // Count は現時点で何回切ったかを表す
	for (int i = 1; i <= N; i++) {
		if (A[i] - Last_Kireme >= x && L - A[i] >= x) {
			Count += 1;
			Last_Kireme = A[i];
		}
	}
	if (Count >= K) return true;
	return false;
}
