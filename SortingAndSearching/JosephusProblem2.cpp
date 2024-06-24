#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace __gnu_pbds;
using namespace std;

//es lo mismo que un ordered set, arbol auto-balanceado que te deja acceder al i-esimo numero en orden en O(log(n))
template <typename T> using indexed_set =  tree<T,\
            null_type, less<T>, rb_tree_tag,\
            tree_order_statistics_node_update>;
 

int main(){
 FIN
 ll n,k;
 cin >> n >> k;
 indexed_set<int> s;
 fore(i,0,n){
    s.insert(i+1);
 }
 int indice = k;
 indexed_set<int> :: iterator it;
 while(s.size() > 1){
        indice %= s.size();
        it = s.find_by_order(indice);
        cout << *it << " ";
        indice += k;
        s.erase(it);

 }
    cout << *s.begin() << endl;
}