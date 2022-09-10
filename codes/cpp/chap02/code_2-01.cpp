for (int d = 1; d <= D; d++) {
	int Answer = 0;

	// for 文で最大値を計算する（変数 i は部屋番号を表す）
	for (int i = 1; i <= N; i++) {
		if (L[d] <= i && i <= R[d]) continue;
		Answer = max(Answer, A[i]);
	}
	cout << Answer << endl;
}
