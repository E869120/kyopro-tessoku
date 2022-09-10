#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009]; // 頂点 x が青色の場合、visited[x] = true

void dfs(int pos) { // pos は現在位置
	visited[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		int nex = G[pos][i];
		if (visited[nex] == false) dfs(nex);
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
	dfs(1);

	// 答えの出力
	string Answer = "The graph is connected.";
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) Answer = "The graph is not connected.";
	}
	cout << Answer << endl;
	return 0;
}
