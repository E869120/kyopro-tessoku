#include <iostream>
using namespace std;
 
int main() {
	// 入力
	int A, B;
	cin >> A >> B;
	
	// 答えを求める
	bool Answer = false;
	for (int i = A; i <= B; i++) {
		if (100 % i == 0) Answer = true;
	}
	
	// 出力
	if (Answer == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
