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

bool ordXSegundos(const pair<ll,pair<ll,ll>> a,const pair<ll,pair<ll,ll>> b){
    if(a.second.first <= b.second.first){
        return true;
    }else{
        return false;
    }
}

ll tr[2*10*10*10*10*10+ 1]; //CuentaCuantosIncluye
ll tr2[2*10*10*10*10*10 + 1];//CuentaCuantosLoIncluyen
void add(int k, int x,int n) {
    while (k <= n) {
        tr[k] += x;
        k += k&-k;
    }
}
int sum(int k) {
    int s = 0;
    while (k >= 1) {
    s += tr[k];
    k -= k&-k;
    }
    return s;
}
void add2(int k, int x,int n) {
    while (k <= n) {
        tr2[k] += x;
        k += k&-k;
    }
}
int sum2(int k) {
    int s = 0;
    while (k >= 1) {
    s += tr2[k];
    k -= k&-k;
    }
    return s;
}






int main(){
    FIN
    int n;
    cin >> n;
    
    unordered_map<ll,int> Maximos;
    pair<ll,pair<ll,int>> rangos[n];
    ll a ,b;
    pair<int,int> res[n];
    fore(i,0,n){
        cin >> a >> b;
        rangos[i].first = a; rangos[i].second.first = b; rangos[i].second.second = i;
    }
    sort(rangos,rangos + n, ordXSegundos);
    int pos = 1;
    ll last = rangos[0].second.first;
    //Asociamos maximos a posiciones
    int act = 0;
    Maximos[rangos[0].second.first] = pos; 
    //Armo el fenwick y asocio valores; //O(nlog(n))
    fore(i,0,n){
        ll buffer = rangos[i].second.first;
        if(last != buffer){
            add(pos ,act,n);
            add2(pos,act,n);
            pos++;
            Maximos[buffer] = pos; 
            act = 1;
            
            last = buffer;
            
        }else{
            act++;
        }
        
    }
    
    add(pos,act,n);
    add2(pos,act,n);
    sort(rangos,rangos + n,compA);
   
   //Primera parte O(nlog(n)) Cuenta de a cuantos contiene;
   fore(i,0,n){
        // 2*log(n);
        int pos = Maximos.at(rangos[i].second.first);    
        res[rangos[i].second.second].first = sum(pos)  -1 ;
        add(pos,-1,n);
   }
    sort(rangos,rangos + n, compB);
    int posFinal = Maximos.at(last); 
    fore(i,0,n){
        int pos = Maximos.at(rangos[i].second.first);

        res[rangos[i].second.second].second =  sum2(posFinal) -(sum2(pos-1)) - 1;
        add2(pos,-1,n); 
    }

    fore(i,0,n){
        cout << res[i].first << " ";
    }
    cout << "\n";
    fore(i,0,n){
        cout << res[i].second << " ";
    }

}
