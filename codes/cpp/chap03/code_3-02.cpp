// 整数 x が何番目に存在するかを返す
int search(int x) {
	int pos = lower_bound(A + 1, A + N + 1, x) - A;
	if (pos <= N && A[pos] == x) return pos;
	return -1;
}
