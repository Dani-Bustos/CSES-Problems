#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b; i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

bool compA(const pair<ll,pair<ll,int>> a, const pair<ll,pair<ll,int>> b){
    if(a.first < b.first){
        return true;
    }else if(a.first > b.first ){
        return false;
    }else if(a.second.first <= b.second.first){
        return true;
    }else{
        return false;
    }
}

int main(){
    
    int n;
    cin >> n;
    pair<ll,pair<ll,int>> invitados[n];
    ll a ,b;
    int res[n];
    fore(i,0,n){
        cin >> a >> b;
        invitados[i].first = a; invitados[i].second.first = b; invitados[i].second.second = i;
    }
    int cuartosMin = 1;
    sort(invitados,invitados + n,compA);
    set<pair<ll,int>> cuartos;
    int actual = 2;
    cuartos.insert({0,1});
  
    for(int i = 0; i<n;i++){
          
        auto it = cuartos.begin();
        pair<ll,int> apuntodeIrse = *it;
        
        if(invitados[i].first > apuntodeIrse.first){
            
            res[invitados[i].second.second] = apuntodeIrse.second;
            cuartos.erase(it);
            pair<ll,int> buffer = {invitados[i].second.first ,apuntodeIrse.second};
            cuartos.insert(buffer);
           
        }else{
            pair<ll,int> buffer = {invitados[i].second.first,actual};
            res[invitados[i].second.second] = actual;
            cuartos.insert(buffer);
            actual++;
            cuartosMin++;
        }
        

        
    }
    cout << cuartosMin << "\n";
    fore(i,0,n){
        cout << res[i] << " ";
    }
}   