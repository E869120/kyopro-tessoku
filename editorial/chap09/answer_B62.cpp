#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// 入力
int N, M, A[100009], B[100009];
 
// 深さ優先探索
vector<int> G[100009];
bool visited[100009];
 
// 深さ優先探索の跡
vector<int> Path, Answer;
 
void dfs(int pos) {
	// ゴール地点にたどり着いた！
	if (pos == N) {
		Answer = Path;
		return;
	}
 
	// その他の場合
	visited[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		int nex = G[pos][i];
		if (visited[nex] == false) {
			Path.push_back(nex); // 頂点 nex を経路に追加
			dfs(nex);
			Path.pop_back(); // 頂点 nex を経路から削除
		}
	}
	return;
}
 
int main() {
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
 
	// 深さ優先探索
	for (int i = 1; i <= N; i++) visited[i] = false;
	Path.push_back(1); // 頂点 1（スタート地点）を経路に追加
	dfs(1);
 
	// 答えの出力
	for (int i = 0; i < Answer.size(); i++) {
		if (i >= 1) cout << " ";
		cout << Answer[i];
	}
	cout << endl;
	return 0;
}
