// 関数 Randouble は 7.3 節の解答例を参照
double TEMP = 180.0 - 179.0 * (clock() - ti) / TIMELIMIT;
double PROB = exp(min(0.0, 1.0 * (NewScore - CurrentScore) / TEMP));
if (Randouble() < PROB) CurrentScore = NewScore;
else Change(t, old_x, old_y, old_h);
