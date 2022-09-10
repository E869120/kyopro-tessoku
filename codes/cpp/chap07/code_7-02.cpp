struct State {
 int score; // 暫定スコア
 int X[29]; // 現在の配列 X の値
 char LastMove; // 最後の動き（'A' または 'B'）
 int LastPos; // Beam[i-1][ どこ ] から遷移したか
};
