#include <iostream>
#include <vector>
using namespace std;
 
class UnionFind {
public:
	int par[100009];
	int siz[100009];
 
	// N 頂点の Union-Find を作成
	void init(int N) {
		for (int i = 1; i <= N; i++) par[i] = -1; // 最初は親が無い
		for (int i = 1; i <= N; i++) siz[i] = 1; // 最初はグループの頂点数が 1
	}
 
	// 頂点 x の根を返す関数
	int root(int x) {
		while (true) {
			if (par[x] == -1) break; // 1 個先（親）がなければ、ここが根
			x = par[x]; // 1 個先（親）に進む
		}
		return x;
	}
 
	// 要素 u と v を統合する関数
	void unite(int u, int v) {
		int RootU = root(u);
		int RootV = root(v);
		if (RootU == RootV) return; // u と v が同グループのときは処理を行わない
		if (siz[RootU] < siz[RootV]) {
			par[RootU] = RootV;
			siz[RootV] = siz[RootU] + siz[RootV];
		}
		else {
			par[RootV] = RootU;
			siz[RootU] = siz[RootU] + siz[RootV];
		}
	}
 
	// 要素 u と v が同一のグループかどうかを返す関数
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};
 
// 入力で与えられる変数・答え
int N, M, A[100009], B[100009];
int Q, QueryType[100009], x[100009], u[100009], v[100009];
string Answer[100009];
 
// その他の変数
UnionFind UF;
bool cancelled[100009];
 
int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i];
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> QueryType[i];
		if (QueryType[i] == 1) cin >> x[i];
		if (QueryType[i] == 2) cin >> u[i] >> v[i];
	}
 
	// 最初に運休になっている路線を求める
	for (int i = 1; i <= M; i++) cancelled[i] = false;
	for (int i = 1; i <= Q; i++) {
		if (QueryType[i] == 1) cancelled[x[i]] = true;
	}
 
	// Union-Find の初期化（その日の最後の状態にする）
	UF.init(N);
	for (int i = 1; i <= M; i++) {
		if (cancelled[i] == false && UF.same(A[i], B[i]) == false) {
			UF.unite(A[i], B[i]);
		}
	}
 
	// クエリを逆から処理
	for (int i = Q; i >= 1; i--) {
		if (QueryType[i] == 1) {
			// 駅 A[x[i]] と駅 B[x[i]] を結ぶ路線が開通
			if (UF.same(A[x[i]], B[x[i]]) == false) UF.unite(A[x[i]], B[x[i]]);
		}
		if (QueryType[i] == 2) {
			if (UF.same(u[i], v[i]) == true) Answer[i] = "Yes";
			else Answer[i] = "No";
		}
	}
 
	// 出力
	for (int i = 1; i <= Q; i++) {
		if (QueryType[i] == 2) cout << Answer[i] << endl;
	}
	return 0;
}
