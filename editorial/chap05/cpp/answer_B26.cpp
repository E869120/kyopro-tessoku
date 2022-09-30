#include <iostream>
using namespace std;

int N;
bool Deleted[1000009]; // 整数 x が消されている場合に限り Deleted[x]=true

int main() {
	// 入力
	cin >> N;

	// エラトステネスのふるい（i は √N 以下の最大の整数までループする）
	for (int i = 2; i <= N; i++) Deleted[i] = false;
	for (int i = 2; i * i <= N; i++) {
		if (Deleted[i] == true) continue;
		for (int j = i * 2; j <= N; j += i) Deleted[j] = true;
	}

	// 答えを出力
	for (int i = 2; i <= N; i++) {
		if (Deleted[i] == false) cout << i << endl;
	}
	return 0;
}
