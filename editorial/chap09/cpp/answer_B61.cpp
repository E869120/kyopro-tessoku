#include <iostream>
#include <vector>
using namespace std;
 
int N, M, A[100009], B[100009];
vector<int> G[100009];
 
int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]); // 「頂点 A[i] に隣接する頂点」として B[i] を追加
		G[B[i]].push_back(A[i]); // 「頂点 B[i] に隣接する頂点」として A[i] を追加
	}
 
	// 次数（= 友達の数）が最大となる生徒の番号を求める
	int MaxFriends = 0; // 友達の数の最大値
	int MaxID = 0;      // 番号
	for (int i = 1; i <= N; i++) {
		if (MaxFriends < (int)G[i].size()) {
			MaxFriends = (int)G[i].size();
			MaxID = i;
		}
	}
 
	// 出力
	cout << MaxID << endl;
	return 0;
}
