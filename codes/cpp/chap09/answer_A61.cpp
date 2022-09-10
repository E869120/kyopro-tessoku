#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> G[100009]; // 隣接リスト

int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]); // 「頂点 A[i] に隣接する頂点」として B[i] を追加
		G[B[i]].push_back(A[i]); // 「頂点 B[i] に隣接する頂点」として A[i] を追加
	}

	// 出力
	for (int i = 1; i <= N; i++) {
		cout << i << ": {";
		for (int j = 0; j < G[i].size(); j++) {
			if (j >= 1) cout << ", ";
			cout << G[i][j];
		}
		cout << "}" << endl;
	}
	return 0;
}
