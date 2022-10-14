struct DSU {
	static const int MAXN = 5005;
	int fa[MAXN];
	void init() {
		fill(fa, fa+MAXN, -1);
	}
	int Find(int x) {
		return ((fa[x] < 0) ? x : fa[x] = Find(fa[x])); // 路徑壓縮
	}
	void U(int x, int y) { 
		x = Find(x), y = Find(y);
		if (x == y) return;
		if (abs(fa[x]) > abs(fa[y])){ // 啟發式合併
			fa[x] += fa[y]; //size
			fa[y] = x; //boss
		}else{
			fa[y] += fa[x];
			fa[x] = y;
		}
		return;
	}
} dsu;