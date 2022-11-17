to_string()
stoi()

std::ios::sync_with_stdio(false);
cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
gp_hash_table<int,int>
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
rbtree.find_by_order

algorithm
reverse(vec.begin(),vec.end())
__gcd(x,y)
__lg(x) // log2(x)
set
set_intersection
set_union
set_difference
set_symmetric_difference
set_union(A.begin(),A.end(),B.begin(),B.end(),inserter( C1 , C1.begin() ) )
upper_bound 大於
lower_bound 大於等於

bitset
.to_ulong()
.flip()
._Find_next(x)
._Find_first()

priority_queue<T, vector<T>, greater<T> >

struct cmp
{
    bool operator()(char* a, char* b)
    {
        return strcmp(a, b) < 0;
    }
};
set<char*, cmp> dictionary;