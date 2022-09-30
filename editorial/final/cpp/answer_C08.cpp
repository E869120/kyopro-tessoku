#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string S[1009]; int T[1009];

// 当選番号が A2 のとき、A1 は何等かを返す
int Hantei(string A1, string A2) {
	int Diff = 0;
	for (int i = 0; i < 4; i++) {
		if (A1[i] != A2[i]) Diff += 1;
	}
	if (Diff == 0) return 1; // 全く同じとき 1 等
	if (Diff == 1) return 2; // 桁が 1 つだけ違うとき 2 等
	return 3;
}

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i] >> T[i];

	// 全探索
	vector<string> Answer;
	for (int num = 0; num <= 9999; num++) {
		// 整数 num を 4 桁の文字列に置き換える
		string ID = to_string(num);
		while (ID.size() < 4) ID = "0" + ID;

		// すべての情報が正しいかどうかを確認
		bool flag = true;
		for (int i = 1; i <= N; i++) {
			if (Hantei(S[i], ID) != T[i]) flag = false;
		}

		// もしすべての情報が正しかった場合
		if (flag == true) {
			Answer.push_back(ID);
		}
	}

	// 出力
	if (Answer.size() != 1) {
		cout << "Can't Solve" << endl;
	}
	else {
		cout << Answer[0] << endl;
	}
	return 0;
}
