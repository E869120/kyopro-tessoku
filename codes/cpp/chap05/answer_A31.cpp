#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	long long A1 = (N / 3); // 3 で割り切れるものの個数
	long long A2 = (N / 5); // 5 で割り切れるものの個数
	long long A3 = (N / 15); // 3, 5 両方で割り切れるもの（= 15 の倍数）の個数
	cout << A1 + A2 - A3 << endl;
	return 0;
}
