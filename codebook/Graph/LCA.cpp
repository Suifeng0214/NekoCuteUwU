int dep[N], Pa[N][lgN], n, root;
void dfs(int now, int d, int pa){
	dep[now] = d;
	Pa[now][0] = pa; // important
	for (auto i : tree[now]){
		if (i != pa) dfs(i, d+1, now);
	}
}
void computePa(){
	for (int i = 0; i < lgN; i++){
		for (int k = 1; k <= n; k++){
			if (Pa[k][i] == -1) Pa[k][i+1] = -1;
			else Pa[k][i+1] = Pa[Pa[k][i]][i];
		}
	}
}
void lca_init(){
	dfs(root, 0, -1); 
	computePa();
}
int lca(int a, int b){
	if (dep[b] > dep[a]) swap(a, b);
	int s = dep[a] - dep[b];
	for (int i = 0; i < lgN; i++){
		if ((s>>i)&1){
			a = Pa[a][i];
		}
	}
	if (a==b) return a;
	for (int i = lgN; i >= 0; i--){
		if (Pa[a][i] != Pa[b][i]){
			a = Pa[a][i];
			b = Pa[b][i];
		}
	}
	return Pa[a][0];
}
int dis(int a, int b){
	int c = lca(a, b);
	return dep[a]+dep[b]-(dep[c]<<1);
}