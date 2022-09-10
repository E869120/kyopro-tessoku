G[pos][i].cap -= flow; // 辺の容量を flow 減少させる
G[G[pos][i].to][G[pos][i].rev].cap += flow; // 逆辺の容量を flow 増加させる
