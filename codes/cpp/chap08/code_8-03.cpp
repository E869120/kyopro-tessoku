auto itr = S.lower_bound(x);
if (itr == S.end()) { // x が S の最大値より大きいとき、itr==S.end() を満たす
	cout << "-1" << endl; // このような場合は -1 を出力
}
else {
	cout << (*itr) << endl; // そうでない場合は通常通り
}
