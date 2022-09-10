// 変数 kakutei[i] は、頂点 i の最短距離が決定したかどうかを表す
for (int i = 1; i <= N; i++) kakutei[i] = false;
for (int i = 1; i <= N; i++) cur[i] = 2000000000;

// 最短距離を更新していく
cur[1] = 0;
while (true) {
	// [ 操作 A] 次に確定する頂点 pos を求める
	int pos = -1;
	int MinDist = 2000000000;
	for (int i = 1; i <= N; i++) {
		if (kakutei[i] == true || MinDist <= cur[i]) continue;
		pos = i;
		MinDist = cur[i];
	}
	if (pos == -1) break; // 次に確定する頂点がない場合、操作終了

	// [ 操作 B] pos と隣接する頂点の cur の値を更新
	kakutei[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		int nex = G[pos][i].first; // 隣接する頂点の番号
		int cost = G[pos][i].second; // 隣接する頂点の長さ
		cur[nex] = min(cur[nex], cur[pos] + cost);
	}
}
