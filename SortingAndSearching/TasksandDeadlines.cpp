#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b; i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
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
    ll n; 
    cin >> n ;
    pair<int,int> tareas[n];
    fore(i,0,n){
        int duracion,deadline;
        cin >> duracion >> deadline;
        tareas[i] = {duracion,deadline};
    }
    
    sort(tareas,tareas + n);
    ll time = 0;
    ll res = 0;
    fore(i,0,n){
        time += tareas[i].first;
        res+= tareas[i].second - time;
        
    }
    cout << res;
}   