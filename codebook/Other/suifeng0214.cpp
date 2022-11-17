1e9+7  1e15+37
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast,no-stack-protector")

bool operator <(my_struct b){
	return x < b.x; // 定義小於為 x 較另一個人的 x 小
}

my_struct operator +(my_struct b){
	return {x+b.x, y+b.y, s+b.s};
}