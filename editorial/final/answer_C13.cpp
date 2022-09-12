#include <iostream>
#include <map>
using namespace std;

// a の b 乗を m で割った余りを返す関数
long long Power(long long a, long long b, long long m) {
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		int wari = (1 << i);
		if ((b / wari) % 2 == 1) {
			Answer = (Answer * p) % m;
		}
		p = (p * p) % m;
	}
	return Answer;
}

// a ÷ b を m で割った余りを返す関数
long long Division(long long a, long long b, long long m) {
	return (a * Power(b, m - 2, m)) % m;
}

long long N, P;
long long A[100009];
map<long long, long long> Count;

int main() {
	// 入力
	cin >> N >> P;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// P=0 の場合
	if (P == 0) {
		long long cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (A[i] == 0) cnt++;
		}
		cout << cnt * (cnt - 1) / 2 + cnt * (N - cnt) << endl;
	}

	// そうでない場合
	if (P != 0) {
		// カード j と i を選ぶとする (j < i)
		// 各 i に対して、何個の j で条件を満たすかを数える
		long long Answer = 0;
		for (int i = 1; i <= N; i++) {
			// A[i]*Goal mod 1000000007 = P を満たす整数が Goal
			long long Goal = Division(P, A[i], 1000000007);
			Answer += Count[Goal];
			Count[A[i]] += 1;
		}
		cout << Answer << endl;
	}
	return 0;
}
