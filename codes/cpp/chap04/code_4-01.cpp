// 答えは dp[1], dp[2], ..., dp[N] の最大値
for (int i = 1; i <= N; i++) {
	dp[i] = 1;
	for (int j = 1; j <= i - 1; j++) {
		if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
	}
}
