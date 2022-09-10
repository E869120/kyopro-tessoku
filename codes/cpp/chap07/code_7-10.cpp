void Yamanobori() {
	// 変数の設定（5.95 秒ループを回す／ CLOCKS_PER_SEC は 1 秒が何ミリ秒かを表す）
	int TIMELIMIT = 5.95 * CLOCKS_PER_SEC;
	int CurrentScore = GetScore();
	int ti = clock();

	// 山登り法スタート
	while (clock() - ti < TIMELIMIT) {
		// (t, new_x, new_y, new_h) の組をランダムに選ぶ
		// 関数 RandInt は 7.2 節の解答例を参照
		int t = RandInt(1, Q);
		int old_x = X[t], new_x = X[t] + RandInt(-9, 9);
		int old_y = Y[t], new_y = Y[t] + RandInt(-9, 9);
		int old_h = H[t], new_h = H[t] + RandInt(-19, 19);
		if (new_x < 0 || new_x >= N) continue;
		if (new_y < 0 || new_y >= N) continue;
		if (new_h <= 0 || new_h > N) continue;

		// とりあえず変更し、スコアを評価する
		Change(t, new_x, new_y, new_h);
		int NewScore = GetScore();

		// スコアに応じて採用／不採用を決める
		if (CurrentScore < NewScore) CurrentScore = NewScore;
		else Change(t, old_x, old_y, old_h);
	}
}
