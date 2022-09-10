#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Union-Find クラスの実装は 9.6 節参照
int N, M;
int A[100009], B[100009], C[100009];
UnionFind UF;

int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];

	// 辺を長さの小さい順にソートする
	vector<pair<int, int>> EdgeList;
	for (int i = 1; i <= M; i++) EdgeList.push_back(make_pair(C[i], i));
	sort(EdgeList.begin(), EdgeList.end());

	// 最小全域木を求める
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
