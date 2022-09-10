// dist[i] の値は ∞ の代わりに非常に大きい値に設定
dist[1] = 0;
for (int i = 2; i <= N; i++) dist[i] = 1000000000;

// Bellman-Ford 法
for (int i = 1; i <= N - 1; i++) {
	for (int j = 1; j <= M; j++) {
		dist[B[j]] = min(dist[B[j]], dist[A[j]] + C[j]);
	}
}

// 答えを出力
for (int i = 1; i <= N; i++) cout << dist[i] << endl;
