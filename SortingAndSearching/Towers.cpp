#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll; 
using namespace std;
 
 
 
int main(){
    FIN
    int n;
    multiset<ll> torres;
    cin >> n;
    ll cajas[n];
    
    fore(i,0,n){
        cin >> cajas[i];
    }
    torres.insert(cajas[0]);
    int res = 1;
    fore(i,1,n){
        auto best = torres.upper_bound(cajas[i]);
        if(best == torres.end() || *best == cajas[i]){
           torres.insert(cajas[i]);
           res++;
        }else {
            torres.erase(best);
            torres.insert(cajas[i]);        
        }
    }
    cout << res;
    
}