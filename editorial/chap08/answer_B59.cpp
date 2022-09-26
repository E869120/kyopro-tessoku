#include <iostream>
#include <algorithm>
using namespace std;
 
class SegmentTree {
public:
	int dat[600000], siz = 1;
 
	// 要素 dat の初期化を行う（最初は全部ゼロ）
	void init(int N) {
		siz = 1;
		while (siz < N) siz *= 2;
		for (int i = 1; i < siz * 2; i++) dat[i] = 0;
	}
 
	// クエリ 1 に対する処理
	void update(int pos, int x) {
		pos = pos + siz - 1;
		dat[pos] = x;
		while (pos >= 2) {
			pos /= 2;
			dat[pos] = dat[pos * 2] + dat[pos * 2 + 1]; // 8.8 節から変更した部分
		}
	}
 
	// クエリ 2 に対する処理
	int query(int l, int r, int a, int b, int u) {
		if (r <= a || b <= l) return 0; // 8.8 節から変更した部分
		if (l <= a && b <= r) return dat[u];
		int m = (a + b) / 2;
		int AnswerL = query(l, r, a, m, u * 2);
		int AnswerR = query(l, r, m, b, u * 2 + 1);
		return AnswerL + AnswerR; // 8.8 節から変更した部分
	}
};
 
int N, A[150009];
SegmentTree Z;
 
int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// セグメント木の準備
	Z.init(N);
 
	// 答えを求める
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		Answer += Z.query(A[i] + 1, N + 1, 1, Z.siz + 1, 1);
		Z.update(A[i], 1);
	}
 
	// 出力
	cout << Answer << endl;
	return 0;
}
