#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
 
long long Q, QueryType[100009], x[100009];
set<long long> Set1, Set2;
 
// r 以下の最大値を返す
long long GetDown(long long r) {
	auto itr = Set2.lower_bound(-r);
 
	// r 以下のものが存在しない場合、非常に小さい値を返す
	if (itr == Set2.end()) return -100000000000000LL;
 
	// 存在する場合
	return -(*itr);
}
 
// r 以上の最小値を返す
long long GetUp(long long r) {
	auto itr = Set1.lower_bound(r);
 
	// r 以上のものが存在しない場合、非常に大きい値を返す
	if (itr == Set1.end()) return 100000000000000LL;
 
	// 存在する場合
	return (*itr);
}
 
int main() {
	// 入力
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> QueryType[i] >> x[i];
 
	// クエリの処理
	for (int i = 1; i <= Q; i++) {
		if (QueryType[i] == 1) {
			Set1.insert(x[i]);
			Set2.insert(-x[i]);
		}
		if (QueryType[i] == 2) {
			long long v1 = GetDown(x[i]);
			long long v2 = GetUp(x[i]);
			long long Answer = min(x[i] - v1, v2 - x[i]);
			if (Answer == 100000000000000LL) cout << "-1" << endl;
			else cout << Answer << endl;
		}
	}
	return 0;
}
