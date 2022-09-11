#include <iostream>
#include <vector>
#include <algorithm>
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
 
// Union-Find クラスの実装は 9.6 節参照
int N, M;
int A[100009], B[100009], C[100009];
UnionFind UF;
 
int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];
 
	// 辺を長さの大きい順にソートする
	vector<pair<int, int>> EdgeList;
	for (int i = 1; i <= M; i++) EdgeList.push_back(make_pair(C[i], i));
	sort(EdgeList.begin(), EdgeList.end());
	reverse(EdgeList.begin(), EdgeList.end()); // 問題 A67 と異なる唯一の部分
 
	// 最大全域木を求める
	int Answer = 0; UF.init(N);
	for (int i = 0; i < EdgeList.size(); i++) {
		int idx = EdgeList[i].second;
		if (UF.same(A[idx], B[idx]) == false) {
			UF.unite(A[idx], B[idx]);
			Answer += C[idx];
		}
	}
	cout << Answer << endl;
	return 0;
}
