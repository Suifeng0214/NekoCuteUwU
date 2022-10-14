#include <bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int N = 1e5+10;

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> tre;
tre st[N];
int dsu[N];

int fp(int x){
	return dsu[x] == x ? x : dsu[x] = fp(dsu[x]); 
}

void U(int x, int y){
	x = fp(x), y = fp(y);
	if (x == y) return;
	if (st[x].size() > st[y].size()) swap(x, y);
	dsu[x] = y;
	for (auto i : st[x]) st[y].insert(i), st[x].erase(i);
	
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> arr;
	arr.resize(N);
	for (int i = 1; i <= n; i++) cin >> arr[i], st[i].insert(arr[i]), dsu[i] = i;
	for (int i = 0; i < m; i++){
		string oper; int x, y;
		cin >> oper >> x >> y;
		if (oper == "A"){
			U(x, y);
		}else if (oper == "M"){
			int p = fp(x);
			st[p].erase(arr[x]);
			arr[x] = y;
			st[p].insert(y);	
		}else{
			int p = fp(x);
			cout << *st[p].find_by_order(y-1) << "\n";
			//求k在樹中是第幾大 t.order_of_key();
			//求樹中的第k大 t.find_by_order();
		}
	}
}