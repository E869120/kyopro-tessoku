for (int k = 1; k <= N; k++) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}
}
