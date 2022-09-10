#include <iostream>
using namespace std;

// a の b 乗を m で割った余りを返す関数
long long Power(long long a, long long b, long long m) {
	long long Answer = 1;
	for (int i = 1; i <= b; i++) Answer = (Answer * a) % m;
	return Answer;
}

int main() {
	long long a, b;
	cin >> a >> b;
	cout << Power(a, b, 1000000007) << endl;
	return 0;
}
