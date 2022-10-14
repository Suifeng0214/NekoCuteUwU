int tree[4*N];
int tag[4*N];
#define MID (l+r)/2
#define lson root*2+1
#define rson root*2+2

void modify(int a,int b,int k,int l,int r,int root){
	tree[root]+=tag[root]*(r-l+1);
	if (l!=r){
		tag[lson]+=tag[root];
		tag[rson]+=tag[root];
	}
	tag[root] = 0;
	if (r<a || l>b) return;
	if (l>=a && r<=b){
		tree[root] += k*(r-l+1);
		if (l!=r){
			tag[lson] += k;
			tag[rson] += k;
		}
	}else{
		int mid = MID;
		modify(a, b, k, l, mid, lson);
		modify(a, b, k, mid+1, r, rson);
		tree[root] = tree[lson]+tree[rson];
	}
}

int Q(int a, int b, int l, int r, int root){
	tree[root]+=tag[root]*(r-l+1);
	if (l!=r){
		tag[lson]+=tag[root];
		tag[rson]+=tag[root];
	}
	tag[root] = 0;
	if (r<a || l>b) return 0;
	if (l>=a && r<=b){
		return tree[root];
	}else{
		int mid = MID;
		int L = Q(a, b, l, mid, lson);
		int R = Q(a, b, mid+1, r, rson);
		return L+R;
	}
}

void build(int l, int r, int root){
	if (l==r){
	   tree[root] = arr[l];
	   return;
	}
	int mid = MID;
	build(l, mid, lson);
	build(mid+1, r, rson);
	tree[root] = tree[lson]+tree[rson];
}
/* 
 * build(0, n-1, 0);
 * modify(a-1, b-1, k, 0, n-1, 0);
 * Q(a-1, b-1, 0, n-1, 0)
 * N < 5e5, Q < 5e5
input:
4
1 2 3 4 // arr = {1, 2, 3, 4}
5
2 1 3
1 1 3 1 // [1,3] + 1
2 1 3 
1 1 4 1
2 1 4

output:
6
9
17
*/