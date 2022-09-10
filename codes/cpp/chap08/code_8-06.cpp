// u は現在のセル番号、[a, b) はセルに対応する半開区間、[l, r) は求めたい半開区間
// 半開区間 [l, r) の最大値を求めるには、query(l, r, 1, siz+1, 1) を呼び出せば良い
int query(int l, int r, int a, int b, int u) {
	if (r <= a || b <= l) return -1000000000; // 一切含まれない場合
	if (l <= a && b <= r) return dat[u]; // 完全に含まれる場合
	int m = (a + b) / 2;
	int AnswerL = query(l, r, a, m, u * 2);
	int AnswerR = query(l, r, m, b, u * 2 + 1);
	return max(AnswerL, AnswerR);
}
