// S = {15, 35, 50} の状態からスタートすることを考える
auto itr1 = S.lower_bound(40);
cout << (*itr1) << endl; // 50 と出力される

itr1--;
cout << (*itr1) << endl; // (1 個小さい ) 35 と出力される

itr1++;
cout << (*itr1) << endl; // (1 個大きい ) 50 と出力される
