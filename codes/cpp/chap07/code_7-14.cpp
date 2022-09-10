// A[Left], A[Left+1], ..., A[Right-1] の最大値を求める関数
int GetMax(int Left, int Right) {
	// 区間に含まれる要素が 1 つになった場合
	if (Right - Left == 1) return A[Left];
	// 左半分と右半分に分割する
	int Mid = (Left + Right) / 2;
	int res1 = GetMax(Left, Mid); // res1 は「左半分の最大値」
	int res2 = GetMax(Mid, Right); // res2 は「右半分の最大値」
	return max(res1, res2);
}
