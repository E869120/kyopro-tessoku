// a 以上 b 以下の整数をランダムに返す関数
int RandInt(int a, int b) {
	return a + rand() % (b - a + 1);
}
