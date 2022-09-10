// 頂点 x の根を返す関数
// 注：親を持たない頂点については「par[x] = -1」と記録する
int root(int x) {
	while (true) {
		if (par[x] == -1) break; // 1 個先（親）がなければ、ここが根
		x = par[x]; // 1 個先（親）に進む
	}
	return x;
}
