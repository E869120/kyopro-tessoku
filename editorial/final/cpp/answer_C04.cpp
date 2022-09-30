#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// 入力
	long long N;
	cin >> N;

	// 約数を列挙
	vector<long long> Yakusuu;
	for (long long i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			Yakusuu.push_back(i);
			if (i != N / i) Yakusuu.push_back(N / i);
		}
	}

	// 小さい順にソート
	sort(Yakusuu.begin(), Yakusuu.end());

	// 出力
	for (int i = 0; i < Yakusuu.size(); i++) {
		cout << Yakusuu[i] << endl;
	}
	return 0;
}
