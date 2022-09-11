#include <iostream>
using namespace std;
 
int N, A[100009];
int Q, L[100009], R[100009];
int Atari[100009], Hazre[100009];
 
int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];
 
	// アタリの個数・ハズレの個数の累積和を求める
	Atari[0] = 0;
	Hazre[0] = 0;
	for (int i = 1; i <= N; i++) {
		Atari[i] = Atari[i - 1]; if (A[i] == 1) Atari[i] += 1;
		Hazre[i] = Hazre[i - 1]; if (A[i] == 0) Hazre[i] += 1;
	}
 
	// 質問に答える
	for (int i = 1; i <= Q; i++) {
		int NumAtari = Atari[R[i]] - Atari[L[i] - 1];
		int NumHazre = Hazre[R[i]] - Hazre[L[i] - 1];
		if (NumAtari > NumHazre) cout << "win" << endl;
		else if (NumAtari == NumHazre) cout << "draw" << endl;
		else cout << "lose" << endl;
	}
	return 0;
}
