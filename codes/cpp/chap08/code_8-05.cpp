void update(int pos, int x) { // セル i に書かれた整数を dat[i] で表す
	pos = pos + siz - 1;
	dat[pos] = x;
	while (pos >= 2) {
		pos /= 2;
		dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
	}
}
