#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b; i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef unsigned long long ll;
class Compare{
public :
bool operator()(const pair<ll,ll> a, const pair<ll,ll> b){
    bool res;
    if(a.first > b.first){
        res = true;
    }else if(a.first < b.first){
        res = false;
    }else if(a.second < b.second){
        res = true;
    }else{
        res = false;
    }
    return res;
}   
};

int main(){
    FIN
    ll n; ll t;
    cin >> n >> t;
    ll maquinas[n];
    fore(i,0,n){
        cin >> maquinas[i];
    }
    sort(maquinas,maquinas + n);
    ll techo = maquinas[n-1]*t;
    ll best = techo;
    
    ll l = 0; ll r = techo;
    for(ll i = techo; i >=1; i/= 2){
        techo = (l + r)/2; 
        ll actual  = 0;
        fore(i,0,n){
            actual += techo/maquinas[i];
            
        }
        if(actual >= t){
            best = min(techo,best);
            r = techo;
        }else{
            l = techo + 1;
        }
    }
    cout << best;
} 