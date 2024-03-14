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
     cin >> a[i];
     presum[i+1] = presum[i] + a[i];
 }
 int i = 1;int j = 1;
 int res = 0; ll act;
 while(i <= n && j <=n){
     if (i  == j) { act = a[i-1];}
     else {act =  presum[j] - presum[i-1];}
    if(act == x){
        res++;
        i++;j++;
    }else if(act > x){
        i++;
    }else {
        j++;
    }
 
 
 }
cout << res;
}
