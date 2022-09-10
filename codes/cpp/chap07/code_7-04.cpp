// sort 関数の順序を決める（スコアが大きい方が「大きい」とする）
bool operator>(const State& a1, const State& a2) {
	if (a1.score > a2.score) return true;
	else return false;
}
