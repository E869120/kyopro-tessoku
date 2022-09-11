#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// 入力される変数・答え
int N, T, A[100009], B[100009];
int Answer[100009];
 
// グラフ・深さ優先探索
vector<int> G[100009];
bool visited[100009];
 
// 深さ優先探索を行う関数（pos は現在位置）
// 返り値は社員 pos の階級
int dfs(int pos) {
	// 最初、社員 pos の階級を 0 に設定する
	visited[pos] = true;
	Answer[pos] = 0;
 
	// 探索をする
	for (int i = 0; i < G[pos].size(); i++) {
		int nex = G[pos][i];
		if (visited[nex] == false) {
			int ret = dfs(nex);
			Answer[pos] = max(Answer[pos], ret + 1); // 階級を更新する
		}
	}
 
	// 値を返す
	return Answer[pos];
}
 
int main() {
	// 入力
	cin >> N >> T;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]); // A[i]→B[i] の方向に辺を追加
		G[B[i]].push_back(A[i]); // B[i]→A[i] の方向に辺を追加
	}
 
	// 深さ優先探索
	dfs(T);
 
	// 出力
	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}
