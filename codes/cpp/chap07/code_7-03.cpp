// 0 手目の状態を設定
// NumState[i] は i 手目時点での状態数（必ずビーム幅以下になる）
// 0 手目は X=[0,0,...,0] しか存在しないので NumState[0]=1
NumState[0] = 1;
Beam[0][0].score = 0;
for (int i = 1; i <= N; i++) Beam[0][0].X[i] = 0;

// ビームサーチ
for (int i = 1; i <= T; i++) {
	vector<State> Candidate;
	for (int j = 0; j < NumState[i - 1]; j++) {
		// 操作 A の場合
		State SousaA = Beam[i - 1][j];
		SousaA.LastMove = 'A';
		SousaA.LastPos = j;
		SousaA.X[P[i]] += 1;
		SousaA.X[Q[i]] += 1;
		SousaA.X[R[i]] += 1;
		for (int k = 1; k <= N; k++) {
			if (SousaA.X[k] == 0) SousaA.score += 1;
		}

		// 操作 B の場合
		State SousaB = Beam[i - 1][j];
		SousaB.LastMove = 'B';
		SousaB.LastPos = j;
		SousaB.X[P[i]] -= 1;
		SousaB.X[Q[i]] -= 1;
		SousaB.X[R[i]] -= 1;
		for (int k = 1; k <= N; k++) {
			if (SousaB.X[k] == 0) SousaB.score += 1;
		}

		// 候補に追加
		Candidate.push_back(SousaA);
		Candidate.push_back(SousaB);
	}

	// ソートして Beam[i] の結果を計算する
	sort(Candidate.begin(), Candidate.end(), greater<State>());
	NumState[i] = min(WIDTH, (int)Candidate.size());
	for (int j = 0; j < NumState[i]; j++) Beam[i][j] = Candidate[j];
}
