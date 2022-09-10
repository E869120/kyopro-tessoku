#include <iostream>
using namespace std;

int GCD(int A, int B) {
	while (A >= 1 && B >= 1) {
		if (A >= B) {
			A = (A % B); // A の値を変更する場合
		}
		else {
			B = (B % A); // B の値を変更する場合
		}
	}
	if (A != 0) return A;
	return B;
}

int main() {
	int A, B;
	cin >> A >> B;
	cout << GCD(A, B) << endl;
	return 0;
}
