#include <iostream>
using namespace std;

int Q, X[10009], N = 300000; // X[i] <= 300000 なので、300000 以下の素数を列挙
bool Deleted[300009]; // 整数 x が消されている場合に限り Deleted[x]=true

int main() {
	// 入力・配列の初期化
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> X[i];
	for (int i = 2; i <= N; i++) Deleted[i] = false;

	// エラトステネスのふるい（i は 以下の最大の整数までループする）
	for (int i = 2; i * i <= N; i++) {
		if (Deleted[i] == true) continue;
		for (int j = i * 2; j <= N; j += i) Deleted[j] = true;
	}

	// 出力
	for (int i = 1; i <= Q; i++) {
		if (Deleted[X[i]] == false) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
