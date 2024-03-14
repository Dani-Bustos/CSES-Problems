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
 
const int MaxN = 2*10*10*10*10*10 + 1;
int a[MaxN];
int main(){
 FIN
 int n;
 cin >> n;
 fore(i,1,n+1){
     cin >> a[i];
 }
 stack<pair<int,int>> s;
 s.push({a[1],1});
 cout << 0 << " ";
 fore(i,2,n+1){
     if(s.top().first < a[i]){
         cout << s.top().second << " ";
         s.push({a[i],i});
     }else{
         while(not s.empty() && s.top().first >= a[i]){
             s.pop();
         }
        if(not s.empty()){
            cout << s.top().second << " ";
        }else{
            cout << 0 << " ";
        }
        s.push({a[i],i});
     }
 }

}
