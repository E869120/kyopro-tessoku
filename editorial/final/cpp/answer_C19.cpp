#include <iostream>
#include <algorithm>
using namespace std;

class SegmentTree {
public:
	long long dat[2100000], siz = 1;

	// 要素 dat の初期化を行う（最初は全部ゼロ）
	void init(int N) {
		siz = 1;
		while (siz < N) siz *= 2;
		for (int i = 1; i < siz * 2; i++) dat[i] = 0;
	}

	// クエリ 1 に対する処理
	void update(int pos, long long x) {
		pos = pos + siz - 1;
		dat[pos] = x;
		while (pos >= 2) {
			pos /= 2;
			dat[pos] = min(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}

	// クエリ 2 に対する処理
	// u は現在のセル番号、[a, b) はセルに対応する半開区間、[l, r) は求めたい半開区間
	long long query(int l, int r, int a, int b, int u) {
		if (r <= a || b <= l) return (1LL << 60); // 一切含まれない場合
		if (l <= a && b <= r) return dat[u]; // 完全に含まれる場合
		int m = (a + b) / 2;
		long long AnswerL = query(l, r, a, m, u * 2);
		long long AnswerR = query(l, r, m, b, u * 2 + 1);
		return min(AnswerL, AnswerR);
	}
};

long long N, L, K;
long long A[700009], C[700009];
long long Min_Value[700009];
SegmentTree Z;

int main() {
	// 入力
	cin >> N >> L >> K;
	for (int i = 1; i <= N; i++) cin >> A[i] >> C[i];

	// 各地点での「値段の最小値」を求める
	for (int i = 1; i <= L - 1; i++) Min_Value[i] = (1LL << 60);
	for (int i = 1; i <= N; i++) Min_Value[A[i]] = min(Min_Value[A[i]], C[i]);

	// セグメント木に載せる
	Z.init(L);
	for (int i = 1; i <= L - 1; i++) Z.update(i, Min_Value[i]);

	// 答えを求める
	long long Answer = 0;
	for (int i = 1; i <= L - K; i++) {
		long long val = Z.query(i, i + K, 1, Z.siz + 1, 1);
		if (val == (1LL << 60)) {
			cout << "-1" << endl;
			return 0;
		}
		Answer += val;
	}
	cout << Answer << endl;
	return 0;
}
