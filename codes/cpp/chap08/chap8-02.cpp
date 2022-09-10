set<int> S;

// 操作を行っていく
S.insert(1); // S = {1}
S.insert(2); // S = {1, 2}
S.insert(4); // S = {1, 2, 4}
S.insert(2); // S = {1, 2, 4} ← ここで {1, 2, 2, 4} にならないことに注意！
cout << S.size() << endl; // 3 と出力される

S.erase(2); // S = {1, 4}
S.insert(9); // S = {1, 4, 9}
S.insert(9); // S = {1, 4, 9} ← ここで {1, 4, 9, 9} にならないことに注意！
cout << S.size() << endl; // 3 と出力される

if (S.count(2) == 1) cout << "2 is included" << endl; // 出力されない
if (S.count(9) == 1) cout << "9 is included" << endl; // 出力される
