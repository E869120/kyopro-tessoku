// 現在のスコアを返す関数
int GetScore() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) sum += abs(A[i][j] - B[i][j]);
	}
	return 200000000 - sum;
}
