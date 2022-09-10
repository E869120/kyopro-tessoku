// 連想配列の定義　　｜ map< 添字の型 , 型 > という形
// 連想配列のアクセス｜通常の配列とほぼ同じ
// ----------------------------------------------------------------

// 添字が string 型、記録する値が int 型の連想配列を定義
map<string, int> Map;

// 連想配列のアクセス
Map["tanaka"] = 49;
Map["suzuki"] = 50;
cout << Map["tanaka"] << endl; // 49 と出力される
cout << Map["suzuki"] << endl; // 50 と出力される

Map["suzuki"] = 53;
cout << Map["suzuki"] << endl; // 53 と出力される
cout << Map["sato"] << endl; // 0 と出力される
