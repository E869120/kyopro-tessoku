// この C++ プログラムは、問題 C20 の解説の 12 ページ目「さらなる高みへ」までを実装したものとなっております。
// これを提出すると、89,056,925 点が得られます（提出によって得点は少し変動します）。

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Union-Find 木
class UnionFind {
public:
	int par[401];
	int siz[401];

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

int N, K, L, A[401], B[401], C[51][51]; vector<int> G[401];
int answer[401];

// 深さ優先探索（9.2 節を参照）
bool visited[401];
void dfs(int pos) {
	visited[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		int nex = G[pos][i];
		if (answer[nex] == answer[pos] && visited[nex] == false) dfs(nex);
	}
}

double get_score() {
	// 答えが正しいかを深さ優先探索 (DFS) を使って確認
	for (int i = 1; i <= K; i++) visited[i] = false;
	for (int i = 1; i <= L; i++) {
		// 特別区 i に属する頂点 pos を探す
		int pos = -1;
		for (int j = 1; j <= K; j++) {
			if (answer[j] == i) {
				pos = j;
			}
		}
		if (pos == -1) return 0.0; // 存在しない特別区がある！
		dfs(pos);
	}
	for (int i = 1; i <= K; i++) {
		if (visited[i] == false) return 0.0; // 連結ではない特別区がある！
	}
	// スコアの計算
	int p[21], q[21];
	for (int i = 1; i <= L; i++) {
		p[i] = 0;
		q[i] = 0;
	}
	for (int i = 1; i <= K; i++) {
		p[answer[i]] += A[i];
		q[answer[i]] += B[i];
	}
	int pmin = *min_element(p + 1, p + L + 1);
	int pmax = *max_element(p + 1, p + L + 1);
	int qmin = *min_element(q + 1, q + L + 1);
	int qmax = *max_element(q + 1, q + L + 1);
	return min(double(pmin) / pmax, double(qmin) / qmax);
}

int main() {
	// 入力
	cin >> N >> K >> L;
	for (int i = 1; i <= K; i++) {
		cin >> A[i] >> B[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> C[i][j];
		}
	}
	
	// グラフの作成
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != N && C[i][j] != 0 && C[i + 1][j] != 0 && C[i][j] != C[i + 1][j]) {
				G[C[i][j]].push_back(C[i + 1][j]);
				G[C[i + 1][j]].push_back(C[i][j]);
			}
			if (j != N && C[i][j] != 0 && C[i][j + 1] != 0 && C[i][j] != C[i][j + 1]) {
				G[C[i][j]].push_back(C[i][j + 1]);
				G[C[i][j + 1]].push_back(C[i][j]);
			}
		}
	}
	// G[i] の重複を取り除く（erase/unique については p.103 のコードを参照）
	for (int i = 1; i <= K; i++) {
		sort(G[i].begin(), G[i].end());
		G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
	}
	
	// 貪欲法（併合を K - L = 380 回繰り返す）
	UnionFind uf;
	uf.init(K);
	for (int i = 1; i <= K - L; i++) {
		int min_size = 1000000000;
		int vertex1 = -1;
		int vertex2 = -1;
		for (int j = 1; j <= K; j++) {
			for (int k = 0; k < G[j].size(); k++) {
				int v = G[j][k];
				if (uf.same(j, v) == false) {
					// 頂点 j の地区と頂点 v の地区を併合すると…？
					int size1 = uf.siz[uf.root(j)];
					int size2 = uf.siz[uf.root(v)];
					if (min_size > size1 + size2) {
						min_size = size1 + size2;
						vertex1 = j;
						vertex2 = v;
					}
				}
			}
		}
		uf.unite(vertex1, vertex2);
	}
	
	// Union-Find 木の状態から答えを出す
	vector<int> roots;
	for (int i = 1; i <= K; i++) {
		roots.push_back(uf.root(i));
	}
	sort(roots.begin(), roots.end());
	roots.erase(unique(roots.begin(), roots.end()), roots.end());
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < roots.size(); j++) {
			if (roots[j] == uf.root(i)) {
				answer[i] = j + 1;
			}
		}
	}
	
	// 山登り法（0.95 秒ループを回す）
	double TIME_LIMIT = 0.95;
	int ti = clock();
	double current_score = get_score();
	while (double(clock() - ti) / CLOCKS_PER_SEC < TIME_LIMIT) {
		int v, x;
		do {
			v = rand() % K + 1; // 1 以上 K 以下のランダムな整数
			x = answer[G[v][rand() % G[v].size()]]; // 頂点 v に隣接する色をランダムに選ぶ
		} while (answer[v] == answer[x]);
		int old_x = answer[v];
		// とりあえず変更し、スコアを評価する
		answer[v] = x;
		double new_score = get_score();
		// スコアの変化に応じて、変更を採用する確率を決める
		double rand_value = double(rand() + 0.5) / (RAND_MAX + 1.0); // 0～1 のランダムな実数
		double temp = 0.0040 - 0.0039 * (double(clock() - ti) / CLOCKS_PER_SEC / TIME_LIMIT);
		if (new_score != 0.0 && rand_value < exp((new_score - current_score) / temp)) {
			current_score = new_score;
		}
		else {
			answer[v] = old_x;
		}
	}
	
	// 出力
	for (int i = 1; i <= K; i++) {
		cout << answer[i] << endl;
	}
	
	return 0;
}