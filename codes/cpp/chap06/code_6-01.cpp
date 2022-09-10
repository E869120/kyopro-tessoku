#include <iostream>
#include <algorithm>
using namespace std;

int N, L[300009], R[300009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// 終了時刻の早いものから貪欲に取っていく（CurrentTime は現在時刻）
	int CurrentTime = 0, Answer = 0;
	while (true) {
		int Min_EndTime = 999999; // 次に選ぶ映画の終了時刻
		for (int i = 1; i <= N; i++) {
			if (L[i] < CurrentTime) continue;
			Min_EndTime = min(Min_EndTime, R[i]);
		}

		// 次に選ぶ映画がある／ない に応じて処理を行う
		if (Min_EndTime == 999999) break;
		CurrentTime = Min_EndTime; Answer += 1;
	}
	cout << Answer << endl;
	return 0;
}
