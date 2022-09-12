#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 入力で与えられる変数
int N, K;
int L[100009], R[100009];

// 時刻 i までに何個出席できるか cntL[i]／時刻 i から何個出席できるか cntR[i]
int cntL[200009];
int cntR[200009];

int main() {
	// 入力
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// 時刻に補正をかける
	for (int i = 1; i <= N; i++) R[i] += K;
	
	// 左から区間スケジューリング（Part1：ソート）
	vector<pair<int, int>> tmp1;
	for (int i = 1; i <= N; i++) tmp1.push_back(make_pair(R[i], L[i]));
	sort(tmp1.begin(), tmp1.end());

	// 左から区間スケジューリング（Part2：貪欲法）
	int CurrentTime1 = 0; // 現在時刻
	int Num1 = 0; // 現在出席した会議の個数
	for (int i = 0; i < tmp1.size(); i++) {
		if (CurrentTime1 <= tmp1[i].second) {
			CurrentTime1 = tmp1[i].first;
			Num1 += 1;
			cntL[CurrentTime1] = Num1;
		}
	}

	// 右から区間スケジューリング（Part1：ソート）
	vector<pair<int, int>> tmp2;
	for (int i = 1; i <= N; i++) tmp2.push_back(make_pair(L[i], R[i]));
	sort(tmp2.begin(), tmp2.end());
	reverse(tmp2.begin(), tmp2.end());

	// 右から区間スケジューリング（Part2：貪欲法）
	int CurrentTime2 = 200000; // 現在時刻
	int Num2 = 0; // 現在出席した会議の個数
	for (int i = 0; i < tmp2.size(); i++) {
		if (CurrentTime2 >= tmp2[i].second) {
			CurrentTime2 = tmp2[i].first;
			Num2 += 1;
			cntR[CurrentTime2] = Num2;
		}
	}

	// cntL, cntR を求める
	// ここで、補正後の R[i] の値は絶対に 200000 を超えないことに注意
	for (int i = 1; i <= 200000; i++) cntL[i] = max(cntL[i], cntL[i - 1]);
	for (int i = 199999; i >= 0; i--) cntR[i] = max(cntR[i], cntR[i + 1]);

	// 答えを求める
	for (int i = 1; i <= N; i++) {
		cout << cntL[L[i]] + cntR[R[i]] + 1 << endl;
	}
	return 0;
}
