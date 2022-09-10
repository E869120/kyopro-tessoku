#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	if (K >= 2 * N - 2 && K % 2 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
