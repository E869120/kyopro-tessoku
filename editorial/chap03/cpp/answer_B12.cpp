#include <iostream>
using namespace std;
 
// 関数 f
double f(double x) {
	return x * x * x + x;
}
 
int main() {
	// 入力
	int N;
	cin >> N;
 
	// 二分探索
	double Left = 0, Right = 100, Mid;
	for (int i = 0; i < 20; i++) {
		Mid = (Left + Right) / 2.0;
		double val = f(Mid);
 
		// 探索範囲を絞る
		if (val > 1.0 * N) Right = Mid; // 左半分に絞られる
		else Left = Mid; // 右半分に絞られる
	}
 
	// 出力
	printf("%.12lf\n", Mid);
	return 0;
}
