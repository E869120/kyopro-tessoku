#include <iostream>
using namespace std;

int main() {
	// ε₯ε
	int N;
	cin >> N;

	// εΊε
	cout << N << endl;
	for (int i = 1; i <= N; i++) {
		cout << i << " " << i % N + 1 << endl;
	}
	return 0;
}
