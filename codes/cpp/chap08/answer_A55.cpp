#include <iostream>
#include <set>
using namespace std;

int main() {
	// 入力
	int Q, QueryType[100009], x[100009];
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> QueryType[i] >> x[i];

	// クエリの処理
	set<int> S;
	for (int i = 1; i <= Q; i++) {
		if (QueryType[i] == 1) S.insert(x[i]);
		if (QueryType[i] == 2) S.erase(x[i]);
		if (QueryType[i] == 3) {
			auto itr = S.lower_bound(x[i]);
			if (itr == S.end()) cout << "-1" << endl;
			else cout << (*itr) << endl;
		}
	}
	return 0;
}
