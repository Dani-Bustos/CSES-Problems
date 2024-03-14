#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

/*** Needs C++11 or C++14 ***/

/// Treap supporting duplicating values in set
/// Maximum value of treap * ADD must fit in long long
//ESTO TAMBIEN SE PUEDE HACER CON UN INDEXED SET NORMAL, USANDO TUPLAS ,  pero me dio vagancia
struct Treap{ /// hash = 96814
    int len;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    tr1::unordered_map <long long, int> mp; /// Change to int if only int in treap
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;

    Treap(){
        len = 0;
        T.clear(), mp.clear();
    }

    inline void clear(){
        len = 0;
        T.clear(), mp.clear();
    }

    inline void insert(long long x){
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c);
    }

    inline void erase(long long x){
        x += MAXVAL;
        int c = mp[x];
        if (c){
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }

    /// 1-based index, returns the K'th element in the treap, -1 if none exists
    inline long long kth(int k){
        if (k < 1 || k > len) return -1;
        auto it = T.find_by_order(--k);
        return ((*it) / ADD) - MAXVAL;
    }

    /// Count of value < x in treap
    inline int count(long long x){
        x += MAXVAL;
        int c = mp[--x];
        return (T.order_of_key((x * ADD) + c));
    }

    /// Number of elements in treap
    inline int size(){
        return len;
    }
};
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
;


 

int main(){
 FIN
 ll n,k;
 cin >> n >> k;
 Treap s;
 int a[n];
 fore(i,0,n){
    cin >> a[i];
 }
 fore(i,0,k-1){
     s.insert(a[i]);
 }
 fore(i,k-1,n){
     s.insert(a[i]);
     if(s.size() % 2 == 1){
         cout << s.kth(( s.size() / 2 ) + 1 ) << " ";
     }else{
         cout << s.kth((s.size() / 2) ) << " ";
     }
    s.erase(a[i - k + 1]);
 }
  
}