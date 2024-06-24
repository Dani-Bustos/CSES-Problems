#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace __gnu_pbds;
using namespace std;

bool compA(const pair<ll,pair<ll,ll>> a,const pair<ll,pair<ll,ll>> b){
    if(a.first < b.first){
        return true;
    }else if(a.first> b.first){
        return false;
    }else if(a.second.first >= b.second.first){
        return true;
    }else{
        return false;
    }
}

bool compB(const pair<ll,pair<ll,ll>> a,const pair<ll,pair<ll,ll>> b){
    return not (compA(a,b));
}









int main(){

    ll n;
    cin >> n;
    pair<ll,pair<ll,ll>> rangos[n];
    pair<ll,ll> res[n];
    
    ll a ,b;
    fore(i,0,n){
        cin >> a >> b;
        rangos[i].first = a; rangos[i].second.first = b; rangos[i].second.second = i;
    }
    sort(rangos, rangos + n,compA);
    ll max = 0;
        fore(i,0,n){
        if(rangos[i].second.first <= max){
            res[rangos[i].second.second].second = 1;
        }else{
            max = rangos[i].second.first;
        }
    }
    sort(rangos,rangos + n, compB); 
    ll min = (ll) pow(10,9) + 1;
    fore(i,0,n){
        if(rangos[i].second.first >= min ){
            res[rangos[i].second.second].first = 1;
        }else{
            min = rangos[i].second.first;
        }
    }
    fore(i,0,n){
        cout << res[i].first << " ";
    }
    cout << "\n";
    fore(i,0,n){
        cout << res[i].second << " ";
    }
}
