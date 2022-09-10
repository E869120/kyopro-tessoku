#include <iostream>
using namespace std;

int main() {
	// 入力部分
	int a, b;
	cin >> a >> b;

	// 出力部分
	cout << (a & b) << endl; // a AND b の値を出力
	cout << (a | b) << endl; // a OR b の値を出力
	cout << (a ^ b) << endl; // a XOR b の値を出力
	return 0;
}
