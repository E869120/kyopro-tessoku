#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

// 入力部分
int N, M, K;
int A[100009], B[100009], S[100009], T[100009];

// (時刻, 出発か到着か, 路線番号または空港番号)
// 出発 = 2／到着 = 1／最初と最後 = 0
// ここで、出発の方が番号が大きい理由は、同じ時刻のときに到着をより早くするため
vector<tuple<int, int, int>> List;

// 頂点番号の情報
int VertS[100009]; // 路線 i の到着
int VertT[100009]; // 路線 i の出発
vector<int> Airport[100009];

// グラフおよび dp[i]
vector<pair<int, int>> G[400009];
int dp[400009];

int main() {
	// 入力
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> S[i] >> B[i] >> T[i];
		T[i] += K; // 到着時刻の補正
	}

	// 頂点となり得る (空港, 時刻) の組を「時刻の早い順に」ソート
	for (int i = 1; i <= M; i++) List.push_back(make_tuple(S[i], 2, i));
	for (int i = 1; i <= M; i++) List.push_back(make_tuple(T[i], 1, i));
	for (int i = 1; i <= N; i++) List.push_back(make_tuple(-1, 0, i));
	for (int i = 1; i <= N; i++) List.push_back(make_tuple(2100000000, 0, i));
	sort(List.begin(), List.end());

	// 各路線の頂点番号を求める
	// ここで、頂点番号は時刻の早い順に 1, 2, ..., List.size() となる
	for (int i = 0; i < List.size(); i++) {
		if (get<1>(List[i]) == 2) VertS[get<2>(List[i])] = i + 1;
		if (get<1>(List[i]) == 1) VertT[get<2>(List[i])] = i + 1;
	}

	// 各空港の頂点番号を求める（空港で待つことに対応する実線を求めるときに使う）
	for (int i = 0; i < List.size(); i++) {
		if (get<1>(List[i]) == 0) Airport[get<2>(List[i])].push_back(i + 1);
		if (get<1>(List[i]) == 1) Airport[B[get<2>(List[i])]].push_back(i + 1);
		if (get<1>(List[i]) == 2) Airport[A[get<2>(List[i])]].push_back(i + 1);
	}

	// グラフを作る（辺が逆向きになっていることに注意！）
	for (int i = 1; i <= M; i++) {
		G[VertT[i]].push_back(make_pair(VertS[i], 1)); // 路線に対応する辺（点線）
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (int)Airport[i].size() - 1; j++) {
			int idx1 = Airport[i][j];
			int idx2 = Airport[i][j + 1];
			G[idx2].push_back(make_pair(idx1, 0)); // 空港で待つことに対応する辺（実線）
		}
	}

	// グラフに始点（頂点 0）と終点（頂点 List.size()+1）を追加
	for (int i = 1; i <= N; i++) {
		G[Airport[i][0]].push_back(make_pair(0, 0));
		G[List.size() + 1].push_back(make_pair(Airport[i][Airport[i].size() - 1], 0));
	}

	// 動的計画法によって dp[i] の値を求める
	// 頂点番号は時刻の早い順になっているので、dp[1] から順に計算すれば良い
	dp[0] = 0;
	for (int i = 1; i <= List.size() + 1; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			dp[i] = max(dp[i], dp[G[i][j].first] + G[i][j].second);
		}
	}

	// 出力
	cout << dp[List.size() + 1] << endl;
	return 0;
}
