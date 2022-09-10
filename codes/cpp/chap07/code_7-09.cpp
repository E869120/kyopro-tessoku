// X[t]=x, Y[t]=y, H[t]=h に変更する関数
void Change(int t, int x, int y, int h) {
	// X[t], Y[t], H[t] の変更
	X[t] = x;
	Y[t] = y;
	H[t] = h;

	// 配列 B のリセット（ゼロに戻す）
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) B[i][j] = 0;
	}

	// 配列 B の更新
	for (int q = 1; q <= Q; q++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				B[j][i] += max(0, H[q] - abs(X[q] - i) - abs(Y[q] - j));
			}
		}
	}
}
