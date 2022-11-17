int __builtin_ffs (unsigned int x)
int __builtin_ffsl (unsigned long)
int __builtin_ffsll (unsigned long long)
// 返回右起第一個1的位置

int __builtin_clz (unsigned int x)
int __builtin_clzl (unsigned long)
int __builtin_clzll (unsigned long long)
// 返回左起第一個1之前0的個數
 
int __builtin_ctz (unsigned int x)
int __builtin_ctzl (unsigned long)
int __builtin_ctzll (unsigned long long)
// 返回右起第一個1之後的0的個數

int __builtin_popcount (unsigned int x)
int __builtin_popcountl (unsigned long)
int __builtin_popcountll (unsigned long long)
// 返回1的個數 

int __builtin_parity (unsigned int x)
int __builtin_parityl (unsigned long)
int __builtin_parityll (unsigned long long)
// 返回1的個數的奇偶性(1的個數 mod 2的值)

// 當你在GCC環境下，想直接用01寫二進位的東西，其實有簡單的方法(C++14以後的版本支援它):
cout << 0b1010101;
cout << 0b1010101LL; // 85

//C++11~，stoi,stol,stoll,stoul,stoull..，可以設定他用二進位轉換，像是這樣:
cout << stoi("1010101",NULL,2);
cout << stoll("1010101",NULL,2); // 85