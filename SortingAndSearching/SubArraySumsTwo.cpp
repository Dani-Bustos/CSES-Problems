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
 
const int MaxN = 2*10*10*10*10*10;
int a[MaxN];
int main(){
 FIN
 int n,x ;
 cin >> n >> x  ;
 ll presum[n+1];
 presum[0] = 0;
 fore(i,0,n){
     int temp;
     cin >> temp;
     a[i] = temp;
     presum[i+1] = presum[i] + a[i];
 }
 int i = 1;int j = 1;
 ll res = 0; ll act;
 map<ll,int> s;
 s[0] = 1;
 while(i <= n && j <=n){
    if (i  == j) { act = a[i-1];}
    else {act =  presum[j] - presum[i-1];}
    //cout << x-act  << " " << act << "\n";
    
    if(s.count(-(x-act)) != 0){
            res += s[-(x-act)];
        
    }
    j++;
    if (s.count(act) == 0) s[act] = 1;
    else{ s[act] = s[act] + 1;}
 
 }
cout << res;
}

